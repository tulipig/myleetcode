#include <iostream>
#include <stack>
#include <memory>
#include <limits.h>
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        _stk.push(x);

        //小于或等于都要压入
        if(_minStk.empty() || x <= _minStk.top())
        {
            _minStk.push(x);
        }
    }
    
    void pop() {
        if(!_minStk.empty() && _stk.top() == _minStk.top())
        {
            _minStk.pop();
        }

        if(!_stk.empty())
        {
            _stk.pop();
        }

    }
    
    int top() {
        return !_stk.empty() ? _stk.top() : INT_MAX;
    }
    
    int getMin() {
        return !_minStk.empty() ? _minStk.top() : INT_MAX;
    }

private:
    stack<int> _stk;
    stack<int> _minStk;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main()
{
    //MinStack* obj = new MinStack();
    std::shared_ptr<MinStack> obj(new MinStack());
    obj->push(8);
    obj->push(4);
    obj->push(6);
    cout << obj->top() << " " << obj->getMin() << endl;
    obj->pop();
    cout << obj->top() << " " << obj->getMin() << endl;
    obj->push(7);
    obj->push(5);
    obj->push(9);
    cout << obj->top() << " " << obj->getMin() << endl;
    obj->pop();
    obj->pop();
    cout << obj->top() << " " << obj->getMin() << endl;
    obj->push(0);
    obj->push(3);
    cout << obj->top() << " " << obj->getMin() << endl;
    obj->pop();
    obj->pop();
    obj->pop();
    obj->pop();
    obj->pop();
    obj->pop();
    cout << obj->top() << " " << obj->getMin() << endl;

    return 0;
}