class Solution {
public:
    string ones[10] = {"",     "One", "Two",   "Three", "Four",
                       "Five", "Six", "Seven", "Eight", "Nine"};
    string teens[10] = {"",         "Eleven",  "Twelve",  "Thirteen",
                        "Fourteen", "Fifteen", "Sixteen", "Seventeen",
                        "Eighteen", "Nineteen"};
    string tens[10] = {"",      "Ten",   "Twenty",  "Thirty", "Forty",
                       "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string thousands[10] = {"", "Thousand", "Million", "Billion"};
    string convert_thous(int num) {
        string res;
        if (num >= 100) {
            res += ones[num / 100] + " Hundred ";
            num %= 100;
        }
        if (num >= 20) {
            res += tens[num / 10] + " ";
            num %= 10;
        } else if (num > 10 && num < 20) {
            res += teens[num - 10] + " ";
            num = 0;
        }
        if (num == 10)
            res+= "Ten";
        if (num > 0) {
            res += ones[num] + " ";
        }
        return res;
    }
    string numberToWords(int num) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        if (num == 0)
            return "Zero";
        string result;
        int tho = 0;
        while (num > 0) {
            int temp = num % 1000;
            if (temp > 0) {
                result = convert_thous(temp) + thousands[tho] + " " + result;
            }
            num /= 1000;
            tho++;
        }
        auto it = std::find_if_not(result.rbegin(), result.rend(), ::isspace);
        result.erase(it.base(), result.end());
        return result;
    }
};