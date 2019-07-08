#include <string>  
#include <iostream>  
#include <unordered_map>  
#include <list>
#include <algorithm>
#include <queue>
using namespace std;  

// int main(int argc, char const *argv[])
// {
//     std::unordered_map<int, std::string> m;
//     m[9] = "hello";
//     m[4] = "world";
//     m[1] = "test";
//     m[-7] = "tulip";
//     m[5] = "thank";
//     m[10] = "you";

//     for(auto& x : m)
//     {
//         std::cout<< x.first << " : " << x.second << std::endl;
//     }

//     return 0;
// }

// struct HeapNode
// {
//     int level;
//     int val;
//     HeapNode(int x, int y):level(x),val(y) {}
//     bool operator<(const HeapNode& node) const
//     { 
//         return this->val < node.val;
//     }
//     bool operator>(const HeapNode& node) const
//     { 
//         return this->val > node.val;
//     }
// };

// int main()
// {
//     priority_queue<HeapNode,std::vector<HeapNode>,greater<HeapNode> > pq;

//     HeapNode node1(1,1);
//     pq.push(node1);
//     HeapNode node2(2,2);
//     pq.push(node2);
//     HeapNode node3(3,3);
//     pq.push(node3);

//     while(!pq.empty())
//     {
//         cout<< pq.top().level << " : " << pq.top().val << endl;
//         pq.pop();
//     }

//     priority_queue<int,vector<int>,greater<int> > pqint;
//     pqint.push(3);
//     pqint.push(4);
//     pqint.push(2);
//     while(!pqint.empty())
//     {
//         cout<< pqint.top() << endl;
//         pqint.pop();
//     }

// }




 
// bool cmp(vector<int> a, vector<int> b)
// {
//     // if(a[0] != b[0]) return a[0] > b[0];
//     // if(a[1] != b[1]) return a[1] > b[1];
//     // if(a[2] != b[2]) return a[2] > b[2];
//     return a[1] < b[1];
// }
 
// int main()
// {
// //    vector<vector<int>> vec = { {1,4,3}, {1,4,7} , {,3,5} , {2,9,4} , {2,5,8} , {3,9,6} };
//     vector<vector<int>> vec = { {1,4,3}, {1,2,7} , {7,3,5} , {2,9,4} , {4,5,8} , {3,9,6} };
    
//     sort(vec.begin(), vec.end(), cmp);
//     //sort(vec.begin(), vec.end());
 
//     for(auto p : vec)
//         cout<<p[0]<<' '<<p[1]<<' '<<p[2]<<endl;
 
//     return 0;
// }

// int main()
// {
//     unordered_map<int,std::vector<int>*> mp(4);
    
//     {
//         std::vector<int> *v = new std::vector<int>();
//         v->push_back(1);
//         v->push_back(2);
//         mp[1]=v;
//     }
    
//     std::vector<int>* vv = mp[1];
    
//     cout<<(*vv)[0]<<endl;
//     cout<<(*vv)[1]<<endl;

    
 
//     return 0;
// }

// int main()
// {
//     unsigned int i=3;
//     int j=-5;
//     cout<<(unsigned)j<<endl;
//     cout<<i-(unsigned)j<<endl;
//     cout<<i-j<<endl;
//     cout<<((((int)2)<<31)-1)<<endl;
//     cout<<((2<<31))<<endl;

    
 
//     return 0;
// }

class Base {
     public:
            virtual void f() { cout << "Base::f" << endl; }
            virtual void g() { cout << "Base::g" << endl; }
            virtual void h() { cout << "Base::h" << endl; }
 
};

void print(){
    cout<<"print"<<endl;
}

int main(){
    typedef void(*Fun)(void);
     
    Base b;

    int** pVtab=(int**)&b;
     
    Fun pFun = NULL;
    pFun = (Fun)pVtab[0][0];
    pFun();
    pFun = (Fun)pVtab[0][1];
    pFun();
    pFun = (Fun)pVtab[0][2];
    pFun();



     
    // cout << "虚函数表地址：" << (int*)(&b) << endl;
    // cout << "虚函数表 — 第一个函数地址：" << (int*)*(int*)(&b) << endl;
     
    // Invoke the first virtual function
    //pFun = (Fun)*((int*)*(int*)(&b));
    // ((Fun)*((int*)*(int*)(&b)))();
    // ((Fun)*((int*)*(int*)(&b)+1))();
    // ((Fun)*((int*)*(int*)(&b)+2))();




    return 0;

}