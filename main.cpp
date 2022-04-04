#include<bits/stdc++.h>

using namespace std;

int g_dep, buc_cap;

struct bucket{
    vector<int> data;
    int local_dep;
    bucket(){
        local_dep=g_dep;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>g_dep>>buc_cap;
    vector<bucket*> dir(1<<g_dep);
    for(int i=0;i<(1<<g_dep);i++){
        dir[i]=new bucket;
    }
    vector<bucket*> to_g=dir;
    while (1){
        int op;cin>>op;
        if(op==2){
            int val;cin>>val;
            int dir_pos=val%(1<<g_dep);
            int found=0;
            for(int i=0;i<dir[dir_pos]->data.size();i++){
                if(dir[dir_pos]->data[i]==val){
                    found=1;
                    break;
                }
            }
            if(found){
                cout<<"FOUND\n";
                continue;
            }
            while (dir[dir_pos]->data.size() == buc_cap) {
                if (g_dep == dir[dir_pos]->local_dep) {
                    for (int i = 0; i < (1 << g_dep); i++) {
                        dir.push_back(dir[i]);
                    }
                    g_dep++;
                }
                
                int mp=dir[dir_pos]->local_dep;
                vector<int> buff;
                vector<int> v2;
                for(int i=0;i<dir[dir_pos]->data.size();i++){
                    if((dir[dir_pos]->data[i])&(1<<mp)){
                        buff.push_back(dir[dir_pos]->data[i]);
                    }else{
                        v2.push_back(dir[dir_pos]->data[i]);
                    }
                }
                dir[dir_pos]->local_dep++;
                dir[dir_pos]->data=v2;
                bucket * nxt = new bucket;
                nxt->local_dep=mp+1;
                nxt->data=buff;
                to_g.push_back(nxt);
                for(int i=(dir_pos%(1<<mp));i<(1<<g_dep);i+=(1<<mp)){
                    if(i&(1<<mp)){
                        dir[i]=nxt;
                    }
                }
                
                dir_pos=val%(1<<g_dep);
            }
            dir[dir_pos]->data.push_back(val);
            cout<<"INSERTED\n";
        }else if(op==3){
            int val;cin>>val;
            int dir_pos=val%(1<<g_dep);
            int found=0;
            for(int i=0;i<dir[dir_pos]->data.size();i++){
                if(dir[dir_pos]->data[i]==val){
                    found=1;
                    break;
                }
            }
            if(found){
                cout<<"FOUND\n";
                continue;
            }else{
                cout<<"NOT_FOUND\n";
                continue;
            }
        }else if(op==4){
            int val;cin>>val;
            int dir_pos=val%(1<<g_dep);
            int found=0;
            for(int i=0;i<dir[dir_pos]->data.size();i++){
                if(dir[dir_pos]->data[i]==val){
                    dir[dir_pos]->data.erase(dir[dir_pos]->data.begin()+i);
                    found=1;
                    break;
                }
            }
            if(found){
                cout<<"DELETED\n";
                continue;
            }else{
                cout<<"NOT_FOUND\n";
                continue;
            }
        }else if(op==5){
            cout<<"global depth"<<" "<<g_dep<<endl;
            cout<<"no_of_buckets"<<" "<<to_g.size()<<endl;
            for(int i=0;i<to_g.size();i++){
                cout<<to_g[i]->data.size()<<" "<<to_g[i]->local_dep;
//                for(int j=0;j<to_g[i]->data.size();j++){
//                    cout<<to_g[i]->data[j]<<" ";
//                }
                cout<<endl;
            }
        }else{
            break;
        }
    }
    return 0;
}
