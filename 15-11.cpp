#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
    static vector<vector<int>> subsets(vector<int>& nums){
        vector<vector<int>> result,result2;
        recursive(nums,result);
        for (int i=0;i<result.size();++i){
            bool flag=true;
            for (int j=0;j<result2.size();++j){
                if (result[i]==result2[j]){
                    flag=false;
                    break;
                }
            }
            if (flag){
                result2.push_back(result[i]);
            }
        }
        return result2;
    }
    static void recursive(vector<int> nums,vector<vector<int>>& result){
        result.push_back(nums);
        vector<int> temp = nums;
        for (int i=0;i<temp.size();++i){
            temp.erase(temp.begin()+i);
            recursive(temp,result);
            temp.insert(temp.begin()+i,nums[i]);
        }
        
    }
};

int main(){
    vector<int> set={1,2,3};
    vector<vector<int>> res;
    res=Solution::subsets(set);
    for (int i=0;i<res.size();++i){
        for (int j=0;j<res[i].size();++j){
            cout<<res[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}