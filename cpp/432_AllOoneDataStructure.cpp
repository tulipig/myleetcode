#include <string>  
#include <iostream>  
#include <unordered_set>  
#include <unordered_map>  
#include <list>
using namespace std;  

class AllOne {
public:
    /** Initialize your data structure here. */
    AllOne() {

    }

    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {//插入在桶的尾部
        if(!_m.count(key)) {//key不存在
            if(_buckets.empty() || (--_buckets.end())->val != 1){//val=1不存在keys
                _buckets.push_back({1, {key}});
                _m[key] = --_buckets.end();
            }
            else{//val=1存在keys
                (--_buckets.end())->keys.insert(key);
                _m[key] = --_buckets.end();
            }
        }
        else{//key存在
		    auto curr = _m[key];
			auto next = --_m[key];
            if(next == _buckets.end() || curr->val+1 != next->val){ //--_m[key]->val+1不存在keys
                auto newBucket = _buckets.insert(curr, {curr->val+1, {key}});
                _m[key] = newBucket;
            }
            else{//--_m[key]->val+1存在keys
                next->keys.insert(key);
                _m[key] = next;
            }

            curr->keys.erase(key);
            if (curr->keys.empty()) _buckets.erase(curr);
        }
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if(!_m.count(key)) return; //key not exist

		auto curr = _m[key];
		auto next = ++_m[key];

		if(curr->val == 1){//exist only one times
			curr->keys.erase(key);
			if (curr->keys.empty()) _buckets.erase(curr);
			_m.erase(key);
			return;
		}

		if(next == _buckets.end() || next->val != curr->val-1){//++_m[key]->val-1 not exist keys
			auto newBucket = _buckets.insert(next,{curr->val-1,{key}});
			_m[key] = newBucket;
		}
		else{//++_m[key]->val-1 exist keys
			next->keys.insert(key);
			_m[key] = next;
		}

		curr->keys.erase(key);
		if (curr->keys.empty()) _buckets.erase(curr);
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
   		return !_buckets.empty() ?  *(_buckets.begin()->keys.begin()) : ""; 
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
   		return !_buckets.empty() ?  *(_buckets.rbegin()->keys.begin()) : ""; 
        
    }

private:
    struct Bucket {int val; unordered_set<string> keys;}; //
    list<Bucket> _buckets; 
    unordered_map<string, list<Bucket>::iterator> _m; //
};



int main()
{
    AllOne allone;
    allone.inc("a");
    allone.inc("b");
    allone.inc("b");
    allone.inc("c");
    cout<< "max key : " << allone.getMaxKey() << ", min key : " << allone.getMinKey() << endl;
    allone.inc("c");
    cout<< "max key : " << allone.getMaxKey() << ", min key : " << allone.getMinKey() << endl;
    allone.inc("c");
    cout<< "max key : " << allone.getMaxKey() << ", min key : " << allone.getMinKey() << endl;
    allone.dec("b");
    cout<< "max key : " << allone.getMaxKey() << ", min key : " << allone.getMinKey() << endl;
    allone.dec("b");
    cout<< "max key : " << allone.getMaxKey() << ", min key : " << allone.getMinKey() << endl;


    return 0;
}
