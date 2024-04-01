#include <iostream>
#include <string>

std::string one[] = { "", "One ", "Two ", "Three ", "Four ", "Five ", "Six ", "Seven ", "Eight ", "Nine ", "Ten ", "Eleven ", "Twelve ", "Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen " };
std::string ten[] = { "", "", "Twenty ", "Thirty ", "Forty ", "Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety " };

std::string numToWords(int n, std::string s) {
    std::string str = "";
    if (n > 19) {
        str += ten[n / 10] + one[n % 10];
    } else {
        str += one[n];
    }

    if (n) {
        str += s;
    }

    return str;
}

std::string convertToWords(long n) {
    std::string out;

    out += numToWords((n / 10000000), "Crore ");
    out += numToWords(((n / 100000) % 100), "Lakh ");
    out += numToWords(((n / 1000) % 100), "Thousand ");
    out += numToWords(((n / 100) % 10), "Hundred ");

    if (n > 100 && n % 100) {
        out += "and ";
    }

    out += numToWords((n % 100), "");

    return out;
}

int main() {
    long n ; std::cin>>n;
    std::cout << n << " in words is: " << convertToWords(n) << std::endl;
    return 0;
}
