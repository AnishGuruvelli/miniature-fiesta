class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int start = 0, total = 0, tank = 0;
        // if car fails at 'start', record the next station
        for (int i = 0; i < gas.size(); i++)
        {
            tank = tank + gas[i] - cost[i];
            if (tank < 0)
            {
                start = i + 1;
                total += tank;
                tank = 0;
            }
        }
        // If the total number of gas is bigger than the total number of cost.
        // There must be a solution.
        return (total + tank < 0) ? -1 : start;
    }
};