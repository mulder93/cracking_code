#include <iostream>
#include <cstdlib>
#include <numeric>

void urlify(char* str, int len)
{
    const int spacesCount = std::accumulate(str, str + len, 0, [](int sum, char symbol) {
        return sum + (symbol == ' ' ? 1 : 0);
    });
    
    int readPosition = len - 1;
    int writePosition = readPosition + spacesCount * 2;
    while (readPosition >= 0) {
        if (str[readPosition] == ' ') {
            str[writePosition--] = '0';
            str[writePosition--] = '2';
            str[writePosition--] = '%';
        } else {
            str[writePosition--] = str[readPosition];
        }
        
        --readPosition;
    }
}

int main()
{
    char str[] = " Hello string  with spaces          ";
    urlify(str, 26);
    std::cout << str;
}
