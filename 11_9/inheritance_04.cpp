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
    // = 0 is a way to tell that this method is there as a placeholder
    //  the derived classes will be implementing this method
    //  so, at runtime, refer to the appropriate implementation of this method
    //this makes the method as a abstract method
    virtual string talk() = 0;
    virtual string getType() = 0;

    //enables a Pet to introduce itself
    void intro(){
        cout << "Hi...my name is " << name
            << " I am a " << getType()
            << " & I say " << talk() << endl;
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

class BigDog : public Dog{
public :
        //constructor of BigDog
        BigDog(string argName) : Dog(argName){

        }
        //the only way that BigDog differs from Dog class
        //  is the way it talks
        //there is no need to implement getType()
        //  as it is happy/ok with being called a Dog
        string talk(){
            return "ARRRRRRRFFFFF";
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
                        //new Pet("generic"), //as Pet is an abstract class,
                            //  we cannot have an instance of it
                        new Dog("Buddy"),
                        new Cat("Princess"),
                        new BigDog("Champ")
                        };
    for( Pet *p : allMyPets){
//        cout << "Hi...my name is " << p->getName()
//            << " I am a " << p-> getType()
//            << " & I say " << p->talk() << endl;
        p->intro();
    }
}