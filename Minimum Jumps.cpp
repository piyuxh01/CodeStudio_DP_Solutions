#include<bits/stdc++.h>

int minimumJumps(vector<int> &arr, int n)

{

    // write your code here

 

    int pos=0;

    int dest=0;

    int jump=0;

 

    if(n==1) return 0;

    else if(arr[0]==0 && n>1) return -1;

 

    for(int i=0;i<n-1;i++){

 

        dest=max(dest,arr[i]+i);

 

        if(pos==i){

            pos=dest;

            jump++;

        }

    }

 

    if(pos>=n-1)

    return jump;

 

    return -1;

}
