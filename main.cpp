#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

enum Theme
{
    Dark,
    Light
};

const string BASE_DIR = "C:\\Users\\Admin\\AppData\\Local\\SumatraPDF";
const string FILE_NAME = "SumatraPDF-settings.txt";
const string DARK = "TextColor = #eeeeee\nBackgroundColor = #111111";
const string LIGHT = "TextColor = #000000\nBackgroundColor = #ffffff  ";

Theme getCurrentTheme(string line);
void toggleTheme(Theme currentTheme);
void colorChange(string color);

int main()
{
    fstream file;
    string ind_file_data;
    vector<string> file_data;
    file.open(BASE_DIR + "\\" + FILE_NAME);

    // file.open("SumatraPDF-settings.txt");

    if (file.fail())
    {
        cout << "Error opening the file";
    }

    int i = 1;
    while (!file.eof())
    {
        if (i > 12)
        {
            break;
        }
        getline(file, ind_file_data);
        file_data.push_back(ind_file_data);
        i++;
    }

    file.close();

    Theme currentTheme = getCurrentTheme(file_data[10]);
    toggleTheme(currentTheme);

    return 0;
}

Theme getCurrentTheme(string line)
{
    if (line.substr(12) == "#eeeeee" || line.substr(13) == "#eeeeee")
    {
        return Theme::Dark;
    }
    return Theme::Light;
}

void colorChange(string color)
{
    fstream file;
    string line;
    file.open(BASE_DIR + "\\" + FILE_NAME);
    // file.open("SumatraPDF-settings.txt");
    int i = 1;
    while (!file.eof())
    {
        if (i > 9)
        {
            file.seekp(243);
            file << endl;
            file << color;
            break;
        }
        i++;
    }
    file.close();
}

void toggleTheme(Theme currentTheme)
{

    if (currentTheme == Theme::Dark)
    {
        colorChange(LIGHT);
    }
    else if (currentTheme == Theme::Light)
    {
        colorChange(DARK);
    }
    else
    {
        exit(0);
    }
}