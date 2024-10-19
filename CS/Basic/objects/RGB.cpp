#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

class Decimal
{
private:
    int decimalNumber;

public:
    Decimal(int decimalNumber)
        : decimalNumber(decimalNumber) {}

    string getHexDecimal() const
    {
        stringstream ss;
        ss << hex << setfill('0') << setw(2) << decimalNumber;
        return ss.str();
    }

    string getBinary() const
    {
        string binary = "";
        int num = decimalNumber;

        while (binary.length() < 8)
        {
            binary = to_string(num % 2) + binary;
            num /= 2;
        }
        while (binary.length() < 8)
        {
            binary = "0" + binary;
        }

        return binary;
    }
};

class HexDecimal
{
private:
    string hexDecimalNumber;

public:
    HexDecimal(const string &hexDecimalNumber)
        : hexDecimalNumber(hexDecimalNumber) {}

    string getBinaryDecimal()
    {
        int decimal = stoi(hexDecimalNumber, nullptr, 16);
        Decimal decimalObj(decimal);
        return decimalObj.getBinary();
    }
};

class RGB
{
private:
    int red;
    int green;
    int blue;

public:
    RGB(int red, int green, int blue)
        : red(red), green(green), blue(blue) {}

    string getHexCode() const
    {
        Decimal redDecimal(red);
        Decimal greenDecimal(green);
        Decimal blueDecimal(blue);

        return "#" + redDecimal.getHexDecimal() + greenDecimal.getHexDecimal() + blueDecimal.getHexDecimal();
    }

    string getBits() const
    {
        // 条件でRGB(0,0,0)の時は書かれていないので、一旦"0"を返すものとする
        if (red == 0 && green == 0 && blue == 0) 
            return "0";

        Decimal redDecimal(red);
        Decimal greenDecimal(green);
        Decimal blueDecimal(blue);

        string redBinary = redDecimal.getBinary();
        string greenBinary = greenDecimal.getBinary();
        string blueBinary = blueDecimal.getBinary();

        string binary = redBinary + greenBinary + blueBinary;

        // 問題の条件により、24ビットにはならないため、先頭の余分な0をを削る
        
        return binary.substr(binary.find("1"), binary.length());
    }

    string getColorShade() const
    {
        string strongColor;
        int strongNumber;

        // 条件にはないが、RGB(0,0,0)の時はblack
        // RGB(255, 255, 255)の時はwhiteを返す
        if (red == 0 && green == 0 && blue == 0)
            return "black";
        
        if (red == 255 && green == 255 && blue == 255)
            return "white";

        if (red == green && green == blue)
            return "grayscale";

        if (red >= green)
        {
            strongColor = "red";
            strongNumber = red;
        }
        else
        {
            strongColor = "green";
            strongNumber = green;
        }

        strongColor = (strongNumber >= blue) ? strongColor : "blue";
        return strongColor;
    }
};

void entry()
{
    RGB color1(0, 153, 255);

    cout << color1.getHexCode() << endl;
    cout << color1.getBits() << endl;
    cout << color1.getColorShade() << endl;

    RGB color2(255, 255, 204);

    cout << color2.getHexCode() << endl;
    cout << color2.getBits() << endl;
    cout << color2.getColorShade() << endl;

    RGB color3(0, 87, 0);

    cout << color3.getHexCode() << endl;
    cout << color3.getBits() << endl;
    cout << color3.getColorShade() << endl;

    RGB color4(123, 123, 123);

    cout << color4.getHexCode() << endl;
    cout << color4.getBits() << endl;
    cout << color4.getColorShade() << endl;
}
int main()
{
    entry();
    return 0;
}