#include <iostream>
#include <string>

using namespace std;

class Files
{
private:
    string fileName;
    string fileExtension;
    string content;
    string parentFolder;

public:
    Files(string fileName, string fileExtension, string content, string parentFolder)
    {
        this->fileName = fileName;
        if (fileExtension == ".word" || fileExtension == ".png" || fileExtension == ".mp4" || fileExtension == ".txt")
            this->fileExtension = fileExtension;
        else
            this->fileExtension = ".txt";

        this->content = content;
        this->parentFolder = parentFolder;
    }

    string getLifetimeBandwidthSize()
    {
        const static int GB = 1000;
        const int BITE_PER_CHAR = 25;
        int fileSize = BITE_PER_CHAR * content.length();

        string answer;
        if (fileSize > GB)
        {
            const string convertedSize = to_string(double(fileSize) / GB);

            return removeUnnecessaryZero(convertedSize) + "GB";
        }

        return to_string(fileSize) + "MB";
    }

    string prependContent(string data)
    {
        content = data + content;

        return content;
    }

    string addContent(string data, int position)
    {
        if (position == 0)
            return prependContent(data);

        if (position == content.length())
        {
            content += data;
            return content;
        }

        return content.substr(0, position) + data + content.substr(position, content.length());
    }

    string showFileLocation()
    {
        return parentFolder + " > " + fileName + fileExtension;
    }

private:
    string removeUnnecessaryZero(string str)
    {
        // to_stringを使うと、8bitになるまで0埋めするので、いらない0を末尾から削る

        while (str.back() == '0')
        {
            str.pop_back();
        }

        if (str.back() == '.')
            str.pop_back();

        return str;
    }
};

void entry()
{
    Files assignment("assignment", ".word", "ABCDEFGH", "homework");
    cout << assignment.getLifetimeBandwidthSize() << endl;
    cout << assignment.prependContent("MMM") << endl;
    cout << assignment.addContent("hello world", 5) << endl;
    cout << assignment.showFileLocation() << endl;

    Files blade("blade", ".txt", "bg-primary text-white m-0 p-0 d-flex justify-content-center", "view");
    cout << blade.getLifetimeBandwidthSize() << endl;
    cout << blade.addContent("font-weight-bold ", 11) << endl;
    cout << blade.showFileLocation() << endl;
}

int main()
{
    entry();
    return 0;
}