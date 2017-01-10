class AllOne {
public:
    /** Initialize your data structure here. */
    AllOne() {
    }

    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
      it = getInt.find(key);
      if (it != getInt.end()) {
        map[key]++;
        int val = map[key];
      }
      else {
        map[key] = 1;
        int val = 1;
      }
      if (maxval > val) {
        
      }
    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
      getInt[key]--;
      if (getInt[key] == 0) {
        map.erase('key');
      }
    }

    /** Returns one of the keys with maximal value. */
    string getMaxKey() {

    }

    /** Returns one of the keys with Minimal value. */
    string getMinKey() {

    }

private:
    map<string, int> getInt;
    int maxval = 0;
    int minval = 0;
    string max;
    string min;
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * string param_3 = obj.getMaxKey();
 * string param_4 = obj.getMinKey();
 */
