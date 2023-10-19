#include <iostream>
#include <string>

using namespace std;

struct MenuItem
{
    string name;
    float price;
};

struct Ticket
{
    int number;
    MenuItem orderedItems[3];
    float total;
};

int main()
{
    MenuItem menu[3];
    Ticket tickets[3];
    int op;

    do
    {
        cout << "Ingrese la opción deseada:" << endl;
        cout << "1. Alta de Menú" << endl;
        cout << "2. Alta de Tickets" << endl;
        cout << "3. Lista de Tickets" << endl;
        cout << "4. Salir" << endl;
        cin >> op;

        switch (op)
        {
        case 1: // Alta de Menú
            for (int i = 0; i < 3; i++)
            {
                cout << "Ingrese el nombre del platillo " << i + 1 << ": ";
                cin.ignore();
                getline(cin, menu[i].name);
                cout << "Ingrese el precio del platillo " << i + 1 << ": ";
                cin >> menu[i].price;
            }
            break;

        case 2: // Alta de Tickets
            for (int i = 0; i < 3; i++)
            {
                cout << "Ingrese el número del ticket " << i + 1 << ": ";
                cin >> tickets[i].number;
                cout << "Ingrese los platillos ordenados separados por coma (máximo 3): ";
                cin.ignore();
                string orderedItems;
                getline(cin, orderedItems);
                int j = 0;
                size_t pos = 0;
                string delimiter = ",";
                while ((pos = orderedItems.find(delimiter)) != string::npos && j < 3)
                {
                    tickets[i].orderedItems[j].name = orderedItems.substr(0, pos);
                    orderedItems.erase(0, pos + delimiter.length());
                    j++;
                }
                tickets[i].orderedItems[j].name = orderedItems;
                tickets[i].total = 0;
                for (int k = 0; k <= j; k++)
                {
                    for (int l = 0; l < 3; l++)
                    {
                        if (tickets[i].orderedItems[k].name == menu[l].name)
                        {
                            tickets[i].total += menu[l].price;
                            break;
                        }
                    }
                }
            }
            break;

        case 3: // Lista de Tickets
            for (int i = 0; i < 3; i++)
            {
                cout << "Número de ticket: " << tickets[i].number << endl;
                cout << "Platillos ordenados: ";
                for (int j = 0; j < 3; j++)
                {
                    if (!tickets[i].orderedItems[j].name.empty())
                    {
                        cout << tickets[i].orderedItems[j].name;
                        if (j < 2 && !tickets[i].orderedItems[j + 1].name.empty())
                        {
                            cout << ", ";
                        }
                    }
                }
                cout << endl;
                cout << "Total: $" << tickets[i].total << endl;
                cout << endl;
            }
            break;

        case 4:
            exit(1);
            break;

        default:
            op = 5;
            cout << "La opción es incorrecta." << endl;
            break;
        }
    } while (op >= 1 || op <= 4);

    system("pause");
}

