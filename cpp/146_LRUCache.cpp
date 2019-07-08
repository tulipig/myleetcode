#include "iostream"
#include "list"
#include "unordered_map"
#include "memory"
using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) {
        _cap = capacity;
    }
    
    int get(int key) {
        if(!_m.count(key)) return -1;//key not exist

        if(_m[key] == _lst.begin()) return _m[key]->value;

        _lst.push_front(*_m[key]);
        _lst.erase(_m[key]);
        _m[key] = _lst.begin();

        return _m[key]->value;
    }
    
    void put(int key, int value) {
        if(!_m.count(key)){//key not exist in list
            _lst.push_front({key,value});
            _m[key] = _lst.begin();
        }
        else{
            _m[key]->value = value; //set value
            get(key);
        }

        if(_lst.size() > _cap){//delete element
            _m.erase(_lst.rbegin()->key);
            _lst.pop_back();
        }
    }

    void print(){
        for(auto& x : _m){
            cout << (x.second)->key  << " : " << (x.second)->value << " --> ";
            //cout << " : " << _m[x] << " --> ";
        }
        cout << "=====================" << endl;
    }

private:
    int _cap;
    struct Node{int key; int value;};
    list<Node> _lst; 
    unordered_map<int, list<Node>::iterator> _m; //key:address
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{
    shared_ptr<LRUCache> cache(new LRUCache(2));
    cache->put(2, 1);
    cache->put(2, 2);
    cache->print();
    cout << cache->get(2) << endl;  
    cache->print();     // returns 1
    cache->put(1, 1);    // evicts key 2
    //cout << cache->get(2) << endl;       // returns -1 (not found)
    cache->print();
    cache->put(4, 1);    // evicts key 1
    cache->print();
    cout << cache->get(2) << endl;       // returns -1 (not found)
    cache->print();
    // cout << cache->get(3) << endl;       // returns 3
    // cout << cache->get(4) << endl;       // returns 4

    // cache->put(2, 1);
    // //cache->print();
    // cout << cache->get(2) << endl; 

    // cache->put(3, 2);
    // cache->print();
    // cout << cache->get(2) << endl; 

    // //cache->print();
    // cout << cache->get(3) << endl; 

    return 0;
}