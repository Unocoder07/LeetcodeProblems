class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
         int differenceCount = 0;
        char charFromStr1 = 0, charFromStr2 = 0;
        for (int index = 0; index < s1.size(); ++index) {
            char charA = s1[index], charB = s2[index];
            if (charA != charB) {
                if (++differenceCount > 2 || (differenceCount == 2 && (charA != charFromStr2 || charB != charFromStr1))) {
                    return false;
                }
                charFromStr1 = charA, charFromStr2 = charB;
            }
        }
        return differenceCount != 1;
    }
};