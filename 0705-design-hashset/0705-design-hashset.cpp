class MyHashSet {
private:
    int set[31251];

    int getMask(int key) {
        return 1 << (key % 32);
    }

public:
    MyHashSet() {
        // key is in the range [1, 1000000]
        // 31251 * 32 = 1000032
        memset(set, 0, sizeof(set));
    }

    void add(int key) {
        set[key / 32] |= getMask(key);
    }

    void remove(int key) {
        if (contains(key)) {
            set[key / 32] ^= getMask(key);
        }
    }

    bool contains(int key) {
        return (set[key / 32] & getMask(key)) != 0;
    }
};