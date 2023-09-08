class Solution {
public:
    double angleClock(int hour, int minutes) {
        if(hour == 12) hour = 0;
        double hourDegree = (hour * 5 * 6) + (0.5 * minutes);
        double minuteDegree = 6 * minutes;
        return min(abs(hourDegree - minuteDegree), 360 - abs(hourDegree - minuteDegree));
    }
};