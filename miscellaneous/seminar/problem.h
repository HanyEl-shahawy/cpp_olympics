struct Animal
{
  virtual std::string Noise() const = 0;
  virtual ~Animal() = default;
};
struct Cat : public Animal
{
  std::string Noise() const override{
    return "meow";
  }
};
struct Dog : public Animal
{
  std::string Noise() const override{
    return "woof";
  }
};
struct Person // you need to know the underlying type
{
  void ReactTo(Animal* _animal){
    if (dynamic_cast<Dog*>(_animal))
      RunAwayFrom(_animal);
    else if (dynamic_cast<Cat*>(_animal))
      TryToPet(_animal);
    // can get more nasty if u need to know certain breed
    // or combination of different animals
  }
};
// lots of ifs, slow
// possible solutions using RTTI( Run Time Type Information):
// 1-
enum Animal_Type = {DOG = 0, CAT, PIG, LIZARD, HORSE, /*...*/};
struct Animal
{
  //...
  virtual Animal_Type GetType() const = 0;
};
Animal_Type Cat::GetType() const {return Animal_Type::CAT;}
Animal_Type Dog::GetType() const {return Animal_Type::DOG;}
// 2-
if (typeid(*_animal) == typeid(Cat))
  TryToPet(_animal)
// Even though typeid() is still RTTI
// , it is more efficient than
// a dynamic_cast in practice. In my own experiments it’s about 3x faster.
// But like I said, let’s ignore that.
// The hand-rolled virtual GetType() (manual RTTI)
// approach is still about 30% faster than the typeid() approach,
// so don’t feel too bad.
// (Timings: http://coliru.stacked-crooked.com/a/146255f5da7329a6)

pros:
The standard alternatives to RTTI require modification
or redesign of the class hierarchy in question.
    Sometimes such modifications are infeasible or undesirable,
    particularly in widely-used or mature code.
RTTI can be useful in some unit tests.
For example, it is useful in tests of factory classes
where the test has to verify that a newly created object
has the expected dynamic type.
It is also useful in managing the relationship
between objects and their mocks.

cons:
Querying the type of an object at run-time frequently
means a design problem. Needing to know the type of
an object at runtime is often an indication that the design
of your class hierarchy is flawed.
Undisciplined use of RTTI makes code hard to maintain.
It can lead to type-based decision trees or switch statements
scattered throughout the code, all of which must be examined
when making further changes.

----------------------
// using single dispatch visitor pattern; dispatch is virtual call
///@brief new type which defines how person react to animal*
struct ReactionVisitor
{
  explicit ReactionVisitor(Person* _person) : person_{_person}
  {}
  Person* person_ = nullptr; // person doing the reacting
};
struct Animal
{
  virtual std::string Noise() const = 0;
  virtual ~Animal() = default;
  virtual void Accept(ReactionVisitor& _visitor) = 0;
};
struct Cat : public Animal
{
  std::string Noise() const override{
    return "meow";
  }
};
struct Dog : public Animal
{
  std::string Noise() const override{
    return "woof";
  }
  Accept(ReactionVisitor& _visitor) override final {
    _visitor.person_.RunAwayFrom(this);
  }
};
void Person::ReactTo(Animal* _animal){
  ReactionVisitor visitor{this};
  _animal->Accept(visitor);
}
// big issue:
// how a person reacts to a dog is defined in animals


// ref:
// https://gieseanw.wordpress.com/2018/12/29/stop-reimplementing-the-virtual-table-and-start-using-double-dispatch/
// https://www.bogotobogo.com/cplusplus/dynamic_cast.php