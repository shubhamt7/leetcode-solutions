class Solution
{
public:
    int numSubarrayBoundedMax(vector<int> &nums, int left, int right)
    {

        int start = 0, end = 0;
        int count = 0;

        int window = 0;

        while (end < nums.size())
        {
            if (nums[end] < left)
                count += window;

            else if (nums[end] > right)
            {
                start = end + 1;
                window = 0;
            }
            else
            {
                window = end - start + 1;
                count += window;
            }

            end++;
        }

        return count;
    }
};