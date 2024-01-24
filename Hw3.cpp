#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

const int MAXFILES = 10;
const int MAXROWS = 1000;

//There are 2 distinct approaches for this problem:
//1. Sequential processing - one file at a time. You need total[MAXROWS] array 
//2. Row-wise processing - open all input files. Read one value from each, total them and output.
//                         need an array of ifstream objects open for reading files in parallel.
//If you are excited, you can implement both!

int main() {
    cout << "Choose operation: \n";
    cout << "1. Read from 'input.txt' and write to 'output.txt'\n";
    cout << "2. Compute row-wise totals from multiple files\n";
    cout << "Enter choice (1 or 2): ";
    int choice;
    cin >> choice;
    cin.ignore();  // clear newline character from input buffer

    if (choice == 1) {
        int value1;
        
        ifstream finput("input.txt");
        if (!finput) {
            cerr << "Error opening 'input.txt' for reading." << endl;
            return 1;
        }
        finput >> value1;
        finput.close();
        
        ofstream foutput("output.txt");
        if (!foutput) {
            cerr << "Error opening 'output.txt' for writing." << endl;
            return 1;
        }
        foutput << value1;
        foutput.close();

        cout << "The value from 'input.txt' has been successfully written to 'output.txt'." << endl;
    } else if (choice == 2) {
        ifstream files[MAXFILES];
        string filename;
        int totals[MAXROWS] = {0};

        cout << "Enter filenames separated by spaces (up to 10): ";
        string line;
        getline(cin, line);
        istringstream iss(line);
        
        int fileCount = 0;
        while (iss >> filename && fileCount < MAXFILES) {
            files[fileCount].open(filename);
            if (!files[fileCount]) {
                cerr << "Error opening " << filename << endl;
                return 1;
            }
            fileCount++;
        }

        for (int i = 0; i < MAXROWS; ++i) {
            int sum = 0;
            for (int j = 0; j < fileCount; ++j) {
                int value;
                if (files[j] >> value) {
                    sum += value;
                } else {
                    cerr << "Mismatch in number of rows among files." << endl;
                    return 1;
                }
            }
            totals[i] = sum;
            if (files[0].eof()) {
                break;
            }
        }

        // Close all opened files
        for (int i = 0; i < fileCount; ++i) {
            files[i].close();
        }

        // Write row-wise totals to "output.txt"
        ofstream foutput("output.txt");
        for (int i = 0; i < MAXROWS && totals[i] != 0; ++i) {
            foutput << totals[i] << endl;
        }
        foutput.close();

        cout << "Row-wise totals written to 'output.txt'." << endl;
    } else {
        cerr << "Invalid choice!" << endl;
    }
    
    return 0;
}