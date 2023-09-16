class BrowserHistory {
private:
    vector<string> urls;
    int page_no;
public:
    BrowserHistory(string homepage) {
        urls.push_back(homepage);
        page_no = 0;
    }
    
    void visit(string url) {
        urls.erase(urls.begin() + page_no + 1, urls.end());
        urls.push_back(url);
        page_no++;
    }
    
    string back(int steps) {
        if(steps > page_no) { page_no = 0; return urls[page_no]; }
        page_no -= steps;
        return urls[page_no];
    }
    
    string forward(int steps) {
        if(steps > urls.size() - page_no - 1) { page_no = urls.size() - 1; return urls[page_no]; } 
        page_no += steps;
        return urls[page_no];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */