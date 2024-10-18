#include <iostream>
using namespace std;

string calculateOneComplement(string bits)
{
    // 　条件的に全部0の場合は、下記を返す
    if (bits == "00000000")
    {
        return "100000000";
    }

    string oneComplement = "";
    for (int i = 0; i < bits.length(); i++)
    {
        oneComplement += (bits[i] == '0') ? '1' : '0';
    }

    return oneComplement;
}

string convertDecimalToBinary(int decimal)
{
    string binary = "";

    while (decimal > 0)
    {
        binary = to_string(decimal % 2) + binary;

        decimal /= 2;
    }

    // 条件は8ビット固定長であるため、足りない分は0埋めする
    while (binary.length() < 8)
    {
        binary = "0" + binary;
    }

    return binary;
}

int convertBinaryToDecimal(string binary)
{
    int number = 1;
    int decimalNumber = 0;

    for (int i = binary.length() - 1; i >= 0; i--)
    {
        decimalNumber += int(binary[i] - '0') * number;

        number *= 2;
    }

    return decimalNumber;
}

string twosComplement(string bits)
{
    string oneComplement = calculateOneComplement(bits);
    int decimalNumber = convertBinaryToDecimal(oneComplement);

    return convertDecimalToBinary(decimalNumber + 1);
}

int main()
{
    cout << twosComplement("11111111") << endl;
    return 0;
}