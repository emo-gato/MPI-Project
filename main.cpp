#include <iostream>
#include <fstream>

class Person {//person class; infected tracks whether the person is infected or not and their id number(check data.in) to see inputs
private:
    int id;
    bool infected;

public:
    Person(int id) : id(id), infected(false) {}//initializes a person and makes him not infected at first
    Person() : id(0), infected(false) {}

    int getId() const {
        return id;//returns the id of person
    }

    bool isInfected() const {
        return infected;//returns infection status
    }

    void infect() {
        infected = true;
    }//gets a person infected
};

class Group {
private:
    Person* persons;//array of persons
    bool** contacts;//matrix
    int numPersons;//people in group P1,P2,..., Pn

public:
    Group(int numPersons) : persons(new Person[numPersons]), contacts(new bool*[numPersons]), numPersons(numPersons) {
        for (int i = 0; i < numPersons; i++) {
            contacts[i] = new bool[numPersons];
            for (int j = 0; j < numPersons; j++) {
                contacts[i][j] = false;
            }
        }
    }//initializing group with n no of people; we need to allocate memory too; all elements in contacts matrix become false

    ~Group() {
        delete[] persons;
        for (int i = 0; i < numPersons; i++) {
            delete[] contacts[i];
        }
        delete[] contacts;//destructor; deallocates memory
    }

    void addContact(int person1, int person2) {
        contacts[person1][person2] = true;
        contacts[person2][person1] = true;//adds contact between two people; the contracted person gets infected
    }

    void infectPerson(int personId) {//recursive function to infect all people an infected individual is in contact with. It checks the matrix
        if (persons[personId].isInfected()) {
            return;
        }

        persons[personId].infect();

        for (int i = 0; i < numPersons; i++) {
            if (i != personId && contacts[personId][i]) {
                infectPerson(i);
            }
        }
    }

    int getCount() const {//calculates how many infected people there are
        int count = 0;

        for (int i = 0; i < numPersons; i++) {
            if (persons[i].isInfected()) {
                count++;
            }
        }

        return count;
    }
};

int main() {
    std::ifstream fin("data.in");
    int n;
    fin >> n;
    Group group(n);

    int person1, person2;
    while (fin >> person1 >> person2) {
        group.addContact(person1 - 1, person2 - 1);
    }

    int patientZero = 2 -1;//if we don't substract 1 we won't get the correct index;

    group.infectPerson(patientZero);//infection starts
    int numar = group.getCount();

    std::cout << numar;
    return 0;
}
