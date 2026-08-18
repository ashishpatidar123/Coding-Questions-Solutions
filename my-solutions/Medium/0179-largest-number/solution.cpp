#include <vector>
#include <string>
#include <algorithm>

class Solution {
private:
    class largerNumbercomparator {
    public:
        bool operator()(const std::string& a, const std::string& b) {
            std::string order1 = a + b;
            std::string order2 = b + a;
            return order2.compare(order1) < 0;
        }
    };

public:
    std::string largestNumber(std::vector<int> A) {
        std::vector<std::string> asString(A.size());
        for (int i = 0; i < A.size(); i++) {
            asString[i] = std::to_string(A[i]);
        }

        std::sort(asString.begin(), asString.end(), largerNumbercomparator());

        if (asString[0] == "0") {
            return "0";
        }

        std::string largestnumber = "";
        for (std::string str : asString) {
            largestnumber += str;
        }
        return largestnumber;
    }
};



