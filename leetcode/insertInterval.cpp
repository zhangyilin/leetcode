/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
  public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
      int start_index, end_index;
      int i;
      for (i=0; i<intervals.size(); ++i){
        if (intervals[i].end >= newInterval.start)   break;
      }
      start_index = i;
      for (; i<intervals.size(); ++i){
        if (intervals[i].start > newInterval.end)   break;
      }
      end_index = i;

      vector<Interval> new_intervals;

      if (start_index == intervals.size()){
        new_intervals = intervals;
        new_intervals.push_back(newInterval);
        return new_intervals;
      }
      if (end_index == 0){
        new_intervals.push_back(newInterval);
        new_intervals.insert (new_intervals.end(), intervals.begin(), intervals.end());
        return new_intervals;
      }
      int minimum = min(intervals[start_index].start, newInterval.start);
      int maximum = max(intervals[end_index-1].end, newInterval.end);
      newInterval.start = minimum;
      newInterval.end = maximum;
      for (i=0; i<start_index; ++i){
        new_intervals.push_back(intervals[i]);
      }
      new_intervals.push_back(newInterval);
      for (i=end_index; i<intervals.size(); ++i){
        new_intervals.push_back(intervals[i]);
      }
      return new_intervals;
    }
};
