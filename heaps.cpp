#include <bits/stdc++.h>

using namespace std;

struct page{
    page * nxt;
    page * prev;
    int count=0;
    int start;
    int curr_size=16;
    vector<int> data;
};

int main() {
    int pg_size;cin>>pg_size;
    page* root = nullptr;
    int tot=0;
    while (1){
        int op;
        cin>>op;
        if(op==1){
            int x,y;cin>>x>>y;
            if(tot==0){
                root=new page;
                tot++;
                root->data.push_back(y);
                root->count++;
                root->curr_size+=x+4;
                continue;
            }
            page * stt=root;
            int flg=0;
            for(int i=0;i<tot;i++){
                if(stt->curr_size+x+4>pg_size){
                    if(stt->nxt!=nullptr) stt=stt->nxt;
                }else{
                    stt->data.push_back(y);
                    stt->count++;
                    stt->curr_size+=x+4;
                    flg=1;
                    break;
                }
            }
            if(!flg){
                page *nw=new page;
                tot++;
                nw->prev=stt;
                nw->prev->nxt= nw;
                stt=nw;
                stt->data.push_back(y);
                stt->count++;
                stt->curr_size+=x+4;
                continue;
            }
        }else if(op==2){
            cout<< tot<<" ";
            page * stt=root;
            for(int i=0;i<tot;i++){
                cout<<stt->count<<" ";
                stt=stt->nxt;
            }
            cout<<endl;
        }else if(op==3){
            int z;cin>>z;
            page * stt=root;
            int x=-1,y=-1;
            for(int i=0;i<tot;i++){
                for(int j=0;j<stt->data.size();j++){
                    if(stt->data[j]==z){
                        x=i;
                        y=j;
                    }
                }
                stt=stt->nxt;
            }
            cout<<x<<" "<<y<<endl;
        }else{
            break;
        }
    }
    return 0;
}
