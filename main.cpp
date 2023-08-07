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

int main()
{
    fstream file;
    string ind_file_data;
    vector<string> file_data;
    // file.open(BASE_DIR + "\\" + FILE_NAME);

    file.open("SumatraPDF-settings.txt");

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
    return 0;
}