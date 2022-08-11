
#define n 7
#define sz 4
#include <vector>

class Solution{
    int arr[n+1][sz];
    void numSolutons(const std::vector<int>& data){
        for (int r = 0; r < n;r++ ){
            for (int idx = 0; idx < sz; idx++){
                if (r == 0){
                    arr[r][idx] = 0;
                    continue;
                }
                if (idx == 0){
                    if (r == data[idx]){
                        arr[r][idx] = 1;
                    }
                    else{
                        arr[r][idx] = 0;
                    }
                    continue;
                }
                //arr[r][idx] = 

            }
        }
        for ()

        
    }

};