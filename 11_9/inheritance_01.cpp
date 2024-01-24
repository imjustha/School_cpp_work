#include <iostream>
#include <string>

using namespace std;

//base class or parent class or super class
class Pet{
public :
    //constructor
    Pet(string argName){
        name = argName;
    }
    string getName(){
        return name;
    }
    //virtual means that this method might be overridden in the derived classes
    //so during runtime, check the type of class and then
    //  invoke the appropriate implementation of this method
    virtual string talk(){
        return "default sound";
    }

    virtual string getType(){
        return "???";
    }
private :
    string name;
};

//class ChildClassName : public ParentClassName
class Dog : public Pet{
public :
    //constructor
    //child's constructor needs to call parent's constructor
    //  to make sure we have a basic object
    //      (which means all the attributes and the operations)
  Dog(string argName) : Pet(argName) {
  }
  //overriding the talk method of Pet's talk method
  string talk(){
    return "Woof Woof";
  }
  string getType(){
    return "Dog";
  }
//private :

};

class Cat : public Pet{
public :
    //constructor
    Cat(string argName) : Pet(argName){
    }
        string talk(){
        return "Purr Purr";
    }
    string getType(){
        return "Cat";
    }
};

int main(){
    /*
    Pet allMyPets[] = { Pet("generic"),
                        Dog("Buddy"),
                        Cat("Princess")
                        };
    for( Pet p : allMyPets){
        cout << "Hi...my name is " << p.getName()
            << " & I say " << p.talk() << endl;
    }
    */

    Pet * allMyPets[] = {
                        new Pet("generic"),
                        new Dog("Buddy"),
                        new Cat("Princess")
                        };
    for( Pet *p : allMyPets){
        cout << "Hi...my name is " << p->getName()
            << " I am a " << p-> getType()
            << " & I say " << p->talk() << endl;
    }
}