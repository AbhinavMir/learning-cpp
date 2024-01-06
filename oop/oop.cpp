#include <iostream>
#include <string>

class Person
{
    private:
        std::string first;
        std::string last;

    public:
        Person(std::string first, std::string last)
        {
            this->first = first;
            this->last = last;
        }

        Person() = default;

        void setFirstName(std::string first) {this->first = first;}
        void setLastName(std::string last) {this->last = last;}
        std::string getName ()
        {
            return first + " " + last;
        }
};

class Employee : public Person 
{};
 
int main() 
{
    Person p;
    p.setFirstName("August");
    std::cout << p.getName() << std::endl;

    Employee e;
    e.setFirstName("Ja");
    std::cout << e.getName() << std::endl;

    return 0; 
}