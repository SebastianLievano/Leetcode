class RandomizedSet {
    set<int> s;
    int numItems;
public:
    RandomizedSet() {
        numItems = 0;
    }
    
    bool insert(int val) {
        if(s.count(val)){
            return false;
        } else {
            s.insert(val);
            numItems++;
            return true;
        }
    }
    
    bool remove(int val) {
        if(s.count(val)){
            s.erase(val);
            numItems--;
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int num = rand() % (numItems);
        auto it = s.begin();
        advance(it, num);
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */