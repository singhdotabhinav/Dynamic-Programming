//Recursive Code
#include <bits/stdc++.h>
using namespace std;
int solve(int e, int f){
    if(e==1)
        return f;
    if(f==0||f==1)
        return f;
    int mn=INT_MAX;
    for(int k=1;k<f;k++){


        int temp= 1 + max(solve(e-1,k-1),solve(e,f-k));
        mn=min(temp,mn);
    }
    return mn;
}
int main(){

    cout<<solve(2,6);
}
//Recursive + memoized

#include <bits/stdc++.h>
using namespace std;

int t[100][10000];
int solve(int e, int f){
    if(e==1)
        return f;
    if(f==0||f==1)
        return f;
    if(t[e][f]!=-1)
        return t[e][f];

    int mn=INT_MAX;

    for(int k=1;k<f;k++){


        int temp= 1 + max(solve(e-1,k-1),solve(e,f-k));
        mn=min(temp,mn);
    }

    return t[e][f]=mn;

}

int main(){

    //int e=4;
    //int f=3;
    //int t[e+1][f+1];
    memset(t,-1,sizeof(t));

    cout<<solve(3,14);
}
//Recursive + memoized + optimized


#include <bits/stdc++.h>
using namespace std;

int t[100][10000];
int solve(int e, int f){
    if(e==1)
        return f;
    if(f==0||f==1)
        return f;
    if(t[e][f]!=-1)
        return t[e][f];

    int mn=INT_MAX;

    for(int k=1;k<f;k++){
        int left,right;
        if(t[e-1][k-1]!=-1)
            left=t[e-1][k-1];
        else{
            left=solve(e-1,k-1);
            t[e-1][k-1]=left;
        }



        if(t[e][f-k]!=-1)
            right=t[e][f-k];
        else{
            right=solve(e,f-k);
            t[e][f-k]=right;
        }

        int temp= 1 + max(left,right);
        mn=min(temp,mn);
    }

    return t[e][f]=mn;

}

int main(){


    memset(t,-1,sizeof(t));

    cout<<solve(2,6);
}


