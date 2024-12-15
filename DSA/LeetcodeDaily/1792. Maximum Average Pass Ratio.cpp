
/*
TC: NLogN + KLogN -> O((N+K)LogN)
SC: O(N)
*/
class Solution
{
private:
    double excessRatio(double pass, double total)
    {
        return (pass + 1) / (total + 1) - pass / total;
    }

public:
    double maxAverageRatio(vector<vector<int>> &classes, int extraStudents)
    {
        priority_queue<pair<double, int>> pq;
        int n = classes.size();

        for (int i = 0; i < n; i++)
        {
            pq.push({excessRatio(classes[i][0], classes[i][1]), i});
        }

        while (extraStudents-- > 0)
        {
            int idx = pq.top().second;
            pq.pop();

            classes[idx][0] += 1;
            classes[idx][1] += 1;

            pq.push({excessRatio(classes[idx][0], classes[idx][1]), idx});
        }

        double answer = 0;
        for (vector<int> &student : classes)
        {
            answer += (1.0 * student[0]) / student[1];
        }

        return answer / n;
    }
};