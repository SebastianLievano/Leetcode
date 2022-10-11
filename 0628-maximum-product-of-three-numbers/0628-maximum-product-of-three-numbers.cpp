class Solution 
{
public:
	int maximumProduct(vector<int>& nums) 
	{
		int n=nums.size();
		sort(nums.begin(),nums.end(),greater<int>());
		long long a=nums[0]*nums[1]*nums[2];
		long long b=nums[0]*nums[n-2]*nums[n-1];

		return max(a,b);
	}
};