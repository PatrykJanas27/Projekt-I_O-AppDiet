#include "informacjeOAplikacji.h"

void informacjeOAplikacji::wypiszInformacje()
{
    ifstream file;
    file.open("informacje.csv", ios::out | ios::app);
    cout << endl;
    for (int i = 1; i <= 6; i++) {
        string field = to_string(i);
        getline(file, field, '\n');
        cout << field << endl;
    }
    file.close();
    system("pause");
}
