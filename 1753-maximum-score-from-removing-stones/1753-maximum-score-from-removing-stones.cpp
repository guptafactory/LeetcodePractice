class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int ans = 0, x = 0, y = 0;
        priority_queue<int> pq;
        pq.push(a);
        pq.push(b);
        pq.push(c);
        while (!pq.empty()) {
            if (pq.size() == 1) break;
            ans++;
            x = pq.top();
            pq.pop();
            y = pq.top();
            pq.pop();
            if (x - 1) pq.push(x - 1);
            if (y - 1) pq.push(y - 1);
        }
        return ans;
    }
};