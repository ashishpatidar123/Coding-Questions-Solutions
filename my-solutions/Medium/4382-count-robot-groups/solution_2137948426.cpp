class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        vector<int> group_speeds;
        int n = position.size();
        int last_pos = position[0];
        int current_speed = speed[0];

        for (int i = 1; i < n; ++i) {
            if (position[i] - last_pos <= distance) {
                current_speed = speed[i];
                last_pos = position[i];
            } else {
                group_speeds.push_back(current_speed);
                last_pos = position[i];
                current_speed = speed[i];
            }
        }
        group_speeds.push_back(current_speed);

        int m = group_speeds.size();
        int count = m;
        int barrier_speed = group_speeds.back();

        for (int i = m - 2; i >= 0; --i) {
            if (group_speeds[i] > barrier_speed) {
                count--;
            } else {
                barrier_speed = group_speeds[i];
            }
        }
        return count;
    }
};