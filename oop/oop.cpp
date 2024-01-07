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
        virtual std::string getName ()
        {
            return first + " " + last;
        }
};

class Employee : public Person 
{
    std::string dept;

    public:
        Employee(std::string firstName, std::string lastName, std::string dept) : Person(firstName, lastName)
        {
            this->dept = dept;
        }

         std::string getName() override
    {
        return "Employee: " + Person::getName() + ", " + dept;
    }
};
 
int main() 
{
    Person p;
    p.setFirstName("August");
    std::cout << p.getName() << std::endl;

    Employee e("James", "Bond", "007");
    e.setFirstName("Ja");
    std::cout << e.getName() << std::endl;

    return 0; 
}