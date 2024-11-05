#include <iostream>
#include <vector>
#include<random>
#include<ctime>

using namespace std;

int rob(vector<int>& nums)
{
    int n = nums.size();

    if(n == 0)
        return 0;

    vector<int> gain(n + 1,0);
    gain[n - 1] = nums[n - 1];

    for(int i = n - 2; i >= 0; i--)
    {
        gain[i] = max(gain[i + 1], gain[i + 2] + nums[i]);
    }

    return gain[0];
}


int main()
{
    vector<int> nums(10);
    srand(static_cast<int>(time(0)));

    for(int i = 0; i < 10; i++)
        nums.push_back(rand() % 100 + 1);

    cout << rob(nums) << endl;

    return 0;
}
