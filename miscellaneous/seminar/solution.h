// visitor pattern implements double dispatching ..
// runtime type of 2 objects

///@brief base type .. each time person needs to
/// act differently to animals, a new struct
/// should inherit from this and type of
/// reaction should be defined
struct AnimalVisitor
{
  virtual void Visit(Cat*) = 0;
  virtual void Visit(Dog*) = 0;
};
struct ReactionVisitor : public AnimalVisitor
{
  explicit ReactionVisitor(Person* _person) : person_(_person){}
  void Visit(Dog* _dog) override{person_.RunAwayFrom(this);}
  void Visit(Cat* _cat) override{person_.TryToPet(this);}
  Person* person_ = nullptr;
};
struct FeedingVisitor : public AnimalVisitor
{
  explicit FeedingVisitor(Person* _person) : person_(_person){}
  void Visit(Dog* _dog) override {person_.GiveDogFood(this);}
  void Visit(Cat* _cat) override {person_.GiveCatFood(this);}
  Person* person_ = nullptr;
};
struct Animal
{
  virtual std::string Noise() const = 0;
  virtual ~Animal() = default;
  virtual void Accept(AnimalVisitor& _visitor) = 0;
};
struct Cat : public Animal
{
  Accept(AnimalVisitor* _visitor){_visitor->Visit(this);}
  std::string Noise() const override{ return "meow";}
};
struct Dog : public Animal
{
  Accept(AnimalVisitor* _visitor){_visitor->Visit(this);}
  std::string Noise() const override{ return "woof";}
};
void Person::ReactTo(Animal* _animal){
  ReactionVisitor visitor{this};
  _animal->Accept(&visitor);
}

