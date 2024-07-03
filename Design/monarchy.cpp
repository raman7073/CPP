#include <bits/stdc++.h>
using namespace std;

class Person
{
public:
    string name;
    bool isAlive;
    list<Person *> child;

    Person(string name)
    {
        this->name = name;
        this->isAlive = true;
    }
};

class Monarchy
{
public:
    unordered_map<string, Person *> personMap;
    string king;

    Monarchy(string aKing)
    {

        this->king = aKing;
        Person *p = new Person(aKing);
        personMap[king] = p;
    }

    void birth(string child, string parent)
    {
        Person *parentObj = personMap[parent];
        Person *childObj = new Person(child);
        parentObj->child.push_back(childObj);
        personMap[child] = childObj;
    }

    void death(string name)
    {
        personMap[name]->isAlive = false;
    }
    void dfs(Person *p, list<string> &suc)
    {
        if (p->isAlive)
            suc.push_back(p->name);
        for (Person *c : p->child)
        {
            dfs(c, suc);
        }
    }
    list<string> getOrderOfSuccession()
    {
        list<string> suc;
        dfs(personMap[king], suc);

        return suc;
    }
};

int main()
{
    Monarchy *m = new Monarchy("king");
    m->birth("andy", "king");
    m->birth("bob", "king");
    m->birth("cath", "king");
    m->birth("matt", "andy");
    m->birth("alex", "bob");
    m->birth("asha", "bob");
    m->death("asha");
    list<string> lst = m->getOrderOfSuccession();
    for (auto it : lst)
    {
        cout << it << " ";
    }
}