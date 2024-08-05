#include <algorithm>
#include <vector>
#include <set>
#include <ctime>
#include <iostream>
using namespace std;

class RandomizedSet {
public:
    RandomizedSet() {
        srand(time(0));
    }

    bool insert(int val) {
        pair p=mySet.insert(val);
        return p.second;
    }

    bool remove(int val) {
        return mySet.erase(val);
    }

    int getRandom() {
        auto it=mySet.begin();
        int random = rand() % mySet.size();
        advance(it, random);
        return *it;
    }
    set<int> mySet;
};


int main()
{
    RandomizedSet* obj = new RandomizedSet();
    cout<<obj->insert(1)<<endl;
    cout<<obj->insert(10)<<endl;
    cout<<obj->insert(20)<<endl;
    cout<<obj->insert(30)<<endl;
    cout<<obj->getRandom()<<endl;
    cout<<obj->getRandom()<<endl;
    cout<<obj->getRandom()<<endl;
    cout<<obj->getRandom()<<endl;
    cout<<obj->getRandom()<<endl;
    cout<<obj->getRandom()<<endl;
    return 0;
}
