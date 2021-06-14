bool compare(vector<int> &a, vector<int> &b)
{
    return a[1] > b[1];
}

class Solution
{
public:
    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
    {

        sort(boxTypes.begin(), boxTypes.end(), compare);

        int units = 0;
        int i = 0;

        while (truckSize > 0 && i < boxTypes.size())
        {

            if (truckSize >= boxTypes[i][0])
            {
                units += boxTypes[i][0] * boxTypes[i][1];
                truckSize -= boxTypes[i][0];
                i++;
            }
            else
            {
                units += truckSize * boxTypes[i][1];
                truckSize = 0;
            }
        }

        return units;
    }
};