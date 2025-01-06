#include <bits/stdc++.h>
using namespace std;

int maxh(vector<int>& h){
    int sum = 0;
    int z = h.size();
    for(int i=0; i<z; i++){
        sum = sum+h[i];
    }
    return sum;
}
int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3) {
    int h1_height = maxh(h1);
    int h2_height = maxh(h2);
    int h3_height = maxh(h3);

    int i = 0, j = 0, k = 0;

    while (i < h1.size() && j < h2.size() && k < h3.size()) {
        if (h1_height == h2_height && h2_height == h3_height) {
            return h1_height;
        }
        
        if (h1_height >= h2_height && h1_height >= h3_height) {
            h1_height -= h1[i];
            i++;
        } else if (h2_height >= h1_height && h2_height >= h3_height) {
            h2_height -= h2[j];
            j++;
        } else {
            h3_height -= h3[k];
            k++;
        }
    }
    //empty
    return 0; 
}
