struct Mex {
    set<int> missing;               // Stores all potential mex values
    unordered_map<int, int> freq;   // Frequency of each element in the current set

    // Initialize with numbers from 0 to n + 1 -> O(n log n) time taken.
    Mex(int n) {
        for (int i = 0; i <= n + 1; i++) 
            missing.insert(i);
    }

    // Add an element to the set
    void add(int x) {
        if (++freq[x] == 1)          
            missing.erase(x);        // Remove from potential mex
    }

    // Remove an element from the set
    void remove(int x) {
        if (--freq[x] == 0)       
            missing.insert(x);       // Reinsert into potential mex
    }

    // Get current mex
    int get() const {
        return *missing.begin();
    }
};
