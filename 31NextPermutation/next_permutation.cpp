// https://leetcode.com/problems/next-permutation/description/ 

# include <algorithm>
# include <iostream>
# include <vector>

using namespace std; 


class Solution {
public:
    void nextPermutation(vector<int>& nums) { // 由于是引用传递, 所以直接在input上修改; 
        
//        nums.push_back(5);
//        nums.push_back(4);
        
//        nums.push_back(2);
//        nums.push_back(1);
        
        
        int position = nums.size()-1; // decrease after position;
        for(int i=nums.size()-1;i>0;i--)
        {
            if(nums[i-1] < nums[i])
            {
                position = i;
                break;
            }
            else
            {
                if(i==1 && nums[0]>nums[1])
                {
                    position = 0;
                }
            }
        }
        
        cout<<"position: "<<position<<endl;
        
        if(position==0) // 排列数已经最大; 
        {
            sort(nums.begin(), nums.end());
        }
        else
        {
            int change = nums.size()-1;
            for(int i=nums.size()-1;i>=position;i--)
            {
                if(nums[i] > nums[position-1])
                {
                    change = i;
                    break;
                }
            }
            
            int temp = nums[position-1];
            nums[position-1] = nums[change];
            nums[change] = temp;
            
            sort(nums.begin()+position, nums.end());
        }
        
    }
};

int main()
{
    vector<int> input = {1,2,3}; 
    Solution test; 
    test.nextPermutation(input); 

    for(int i=0;i<input.size();i++)
    {
        cout<<input[i]<<" ";
    }
    cout<<endl;

    return 0; 
}
