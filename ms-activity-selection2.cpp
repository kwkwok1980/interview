// https://www.geeksforgeeks.org/problems/activity-selection-1587115620/1

struct Solution {
    using Schedule = std::pair<int, int>;
    using Schedules = std::vector<Schedule>;
  
    int activitySelection(std::vector<int> &start, std::vector<int> &finish) {
        int N = start.size();
        schedules_ = Schedules(N, {0, 0});
        for (int i=0; i<N; ++i) {
            schedules_[i].first = start[i];
            schedules_[i].second = finish[i];
        }
        std::sort(schedules_.begin(), schedules_.end());
        results_ = std::vector<int>(N, 0);
        results_[N-1] = 1;
        for (int i=N-2; i>=0; --i) {
            solve(i);    
        }
        return results_[0];
    }
    
    void solve(int n) {
        int N = results_.size();
        int start = schedules_[n].first;
        int end = schedules_[n].second;
        int result = results_[n+1];
        for (int i=n+1; i<N; ++i) {
            if (end < schedules_[i].first) {
                result = std::max(result, results_[i] + 1);    
                break;
            }
        }
        results_[n] = result;
    }
    
    Schedules schedules_{};
    std::vector<int> results_{};
};
