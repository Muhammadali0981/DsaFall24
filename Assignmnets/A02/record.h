#ifndef RECORD_H
#define RECORD_H
#include<iostream>

class Record{
    int id;
    std::string name;
    int age;

    public:
    Record() {}
    Record(int id, std::string name, int age): id(id), name(name), age(age) {}

    int getId() { return id; }
    std::string getName() { return name; }
    int getAge() { return age; }

    void setId(int newId) { id = newId; }
    void setName(const std::string& newName) { name = newName; }
    void setAge(int newAge) { age = newAge; }

};

#endif