#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main(int argc, char **argv)
{
    string filename = argv[1];
    cout << "Filename: " << filename << endl;
    ifstream input(argv[1]);
    if (!input.good() )
    {
        cerr << "Error opening '" << filename << "'. Bailing out.\n";
    }
    string header = filename.substr(0, filename.size()-4);
    cout << "Header: >" << header << endl;
    string outname = header;
    outname.append(".txt");
    cout << "Outname: " << outname << endl;
    string sequence;
    string line;
    while (getline(input,line).good() )
    {
        if (line[0] == '>')
        {
            continue;
        }
        else if (!line.empty() && line[0] != '>')
        {
            sequence += line;
        }
    }
    ofstream out;
    out.open(outname);
    int pos = 0;
    out << ">" << header << endl;
    for (string::iterator strint = sequence.begin(); strint != sequence.end(); ++strint)
    {
        out << *strint;
        ++pos;
        if (pos % 60 == 0)
        {
            out << endl;
        }
    }
    out << endl;
    out.close();

    return 0;
}
