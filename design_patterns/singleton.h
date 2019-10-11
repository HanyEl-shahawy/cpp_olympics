//
// Created by elshahawy on 11.10.2019.
//

#ifndef CPP_OLYMPICS_SINGLETON_H
#define CPP_OLYMPICS_SINGLETON_H

class singleton
{
public:
  static singleton& get_instance()
  {
    static singleton instance;
    return instance;
  }

  // copy constructor
  singleton(const singleton& rhs) = delete;
  // move constructor
  singleton(singleton&& rhs) = delete;
  // copy assignment
  singleton& operator=(const singleton& rhs) = delete;
  // move assignment
  singleton& operator=(singleton&& rhs) = delete;
private:
  singleton(){}

};

#endif // CPP_OLYMPICS_SINGLETON_H
