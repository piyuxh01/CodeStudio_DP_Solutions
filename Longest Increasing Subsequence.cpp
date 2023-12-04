#include<bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> v;
    v.push_back(arr[0]);

    for(int i = 1; i < n; i++){
        if(arr[i] > v.back()){
            v.push_back(arr[i]);
        }
        else{
            int index = -1; // Initialize index to -1
            for(int j = 0; j < v.size(); j++){
                if(arr[i] <= v[j]){
                    index = j;
                    break;
                }
            }
            if(index != -1){
                v[index] = arr[i];
            }
        }
    }

    return v.size();
}
