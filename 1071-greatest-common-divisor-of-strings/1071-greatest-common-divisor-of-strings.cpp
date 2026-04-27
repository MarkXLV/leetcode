class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int len1 = str1.size(), len2 = str2.size();

        auto isDivisor = [&](int l) {
            if (len1 % l != 0 || len2 % l != 0) {
                return false;
            }
            string sub = str1.substr(0, l);
            int f1 = len1 / l, f2 = len2 / l;
            string repeated1 = "", repeated2 = "";
            for (int i = 0; i < f1; ++i) repeated1 += sub;
            for (int i = 0; i < f2; ++i) repeated2 += sub;
            return repeated1 == str1 && repeated2 == str2;
        };

        for (int l = min(len1, len2); l > 0; l--) {
            if (isDivisor(l)) {
                return str1.substr(0, l);
            }
        }

        return "";
    }
};