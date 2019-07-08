#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        if(path.length()==0) return path;
        if(path==".") return "/";
        cout<<"00path="<<path<<endl;
        
        //delete odd '.'
        string::iterator pre=path.begin();
        string::iterator it=path.begin();
        while(it!=path.end()){
            if(*it=='.') {
                if((it+1)!=path.end() && *(it+1)!='.'){
                    it=path.erase(it);
                }
                else if((it+1)==path.end()){
                    it=path.erase(it); 
                }
                else if((it+1)!=path.end() && *(it+1)=='.'){
                    ++it;
                    ++it;
                }
            }
            else{
                ++it;
            }
        }
        cout<<"11path="<<path<<endl;
        
        //delete odd '/'
        pre = path.begin();
        for(it=path.begin()+1;it!=path.end();++it){
            while(*pre=='/' && *it=='/') path.erase(it);
            pre=it;
        }

        cout<<"22path="<<path<<endl;

        // "/../c"
        if(path.length()>=4){
            if(path[0]=='/' && path[1]=='.' && path[2]=='.' && path[3]=='/'){
                path="/";
            }
        }

        cout<<"33path="<<path<<endl;
        
        //delete "/d/.."
        pre = path.begin();
        it=path.begin()+1;
        while(it!=path.end()){
            if(*pre=='.' && *it=='.'){
                string::iterator end = it;
                bool found = false;
                while(end>path.begin()){
                    if(!found && *end!='/' && *end!='.') found=true;
                    else if(found && *end=='/') {
                        it=path.erase(end,it+1);
                        break;
                    } 
                    end--;
                }
                continue;
            }
            pre = it;
            ++it;
        }

        cout<<"44path="<<path<<endl;

        return path;
    }
};

int main()
{
    Solution sol;
    cout<<sol.simplifyPath("/a/./b/../../c/")<<endl;

    return 0;
}