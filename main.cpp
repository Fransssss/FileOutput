// Author: Fransiskus Agapa
// 8/15/22
// Practices make improvement - Have fun !

#include <iostream>
#include "string"
#include "fstream"

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::getline;
using std::ofstream;
using std::ifstream;

int main()
{

    cout << "\n== File Output ==" << endl;
    cout << "1. Create a file" << endl;
    cout << "2. Write into the file" << endl;
    cout << "3. Open the file" << endl;
    cout << "e. Exit" << endl;
    cout << "choice: ";
    ofstream onFS;                             // output file stream
    ifstream inFS;                             // input file stream
    string choice;
    string title;
    cin >> choice;

    while(choice != "e" and choice != "E")
    {
        if(choice == "1")
        {
            cout << "\n= Create a file =" << endl;
            cout << "Input file name: ";
            cin >> title;
            title += ".txt";                   // add file extension/type
            onFS.open(title);               // if file exist then open/ if not then create new one
            if(onFS.is_open())
            {
                cout << "\n[ File " << title << " created ]" << endl;
                onFS.close();                  // close file so it can be accessed later
            }
            else
            {
                cout << "\n[ Failed to creat " << title << endl;
            }
        }
        else if(choice == "2")
        {
            if(title.size() == 0)           // if file has not been created
            {
                cout << "\n[ No file to open and write into ]" << endl;
            }
            else
            {
                onFS.open(title);         // open file
                {
                    if(onFS.is_open())
                    {
                        cout << "\n= Input data in to file =" << endl;
                        onFS << "There is no need to light a night-light On a light night"                     // put this data into the file via onFS
                                " like tonight;\nFor a night-light’s light’s a slight light "
                                "When the moonlight’s white and bright." << endl;

                        onFS.close();
                        cout << "\n[ File updated ]" << endl;
                    }
                    else
                    {
                        cout << "\n[ File cannot be opened ]" << endl;
                    }
                }
            }
        }
        else if(choice == "3")
        {
            if(title.size() == 0)
            {
                cout << "\n[ No file to open and write into ]" << endl;
            } else {
                cout << "\n= Open file =\n" << endl;
                inFS.open(title);                                                          // access/read file via inFS
                if (inFS.is_open())
                {
                    string line;
                    while (!inFS.eof())
                    {
                        getline(inFS, line);
                        cout << line << endl;
                    }
                    inFS.close();
                }
                else
                {
                    cout << "\n[ File cannot be opened ]" << endl;
                }
            }
        }
        else
        {
            cout << "\n[ Invalid choice ]" << endl;
        }

        cout << "\n== File Output ==" << endl;
        cout << "1. Create a file" << endl;
        cout << "3. Write into the file" << endl;
        cout << "3. Open the file" << endl;
        cout << "e. Exit" << endl;
        cout << "choice: ";
        cin >> choice;

    }

    if(choice == "e" or choice == "E")
    {
        cout << "\n== Exit Program ==" << endl;
    }

    return 0;
}
