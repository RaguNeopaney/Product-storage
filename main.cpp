#include "Node.h"
#include "part.h"
#include <iostream>


using namespace std;

int main()
{
    Linkedlist<string> s;
    try
    {
        int sku, quantity,ans = 0;
        string Des,Unitofmea;
        double price;
        do
        {
            // here is the menu
            cout << "Choose the following operations " << endl;
            cout << "1. Add Item\t\t2.Get item" << endl;
            cout << "3. Check if List is Empty\t4.Check in List" << endl;
            cout << "5. See next item\t6.See previous Item" << endl;
            cout << "7. See at location\t8.Reset" << endl;
            cout << "9. To End" << endl;
            cin >> ans;

            if (ans == 1)
            {
                cout << "Enter SKU: "; cin >> sku;
                cout << "Enter Product description: "; cin >> Des;
                cout << "Enter UOM (Unit of Measure): "; cin >> Unitofmea;
                cout << "Enter price: "; cin >> price;
                cout << "Enter Quantatiy on Hand: "; cin >> quantity;

                s.AddItem(sku, Des, price, Unitofmea, quantity);

            }
            else if (ans == 2)
            {
                cout << "Enter SKU: "; cin >> sku;
                cout << "SKU: " << sku << "\n" << "Description: " << s.GetItem(sku) << endl << endl;
            }
            else if(ans == 3)
            {
                bool isempty = s.IsEmpty();
                if (isempty)
                {
                    cout << "The list is empty" << endl<<endl;
                }
                else
                {
                    cout << "The list is not Empty" << endl<<endl;
                }
            }
            else if(ans == 4)
            {
                cout << "Enter SKU: "; cin >> sku;
                bool inlist = s.IsInlist(sku);
                if (inlist)
                {
                    cout << "The item is in the list" << endl<<endl;
                }
                else
                {
                    cout << "The item is not in the list" << endl<<endl;
                }
            }
            else if (ans == 5)
            {
                int next_sku = s.SeeNext();
                cout << "The next items sku is " << next_sku << endl<<endl;
            }
            else if (ans == 6)
            {
                cout << "The previous items sku is " << s.SeePrev() << endl<<endl;
            }
            else if (ans == 7)
            {
                cout << "Enter SKU: "; cin >> sku;
                cout << "SKU: " << sku <<"\n"<< "Description: " << s.SeeAt(sku) << endl<<endl;
            }
            else if (ans == 8)
            {
                s.Reset();
                cout << "The pointers location has be reset" << endl<<endl;
            }
            else
            {
                continue;
            }

        } while (ans != 9);

    }
    catch (Linkedlist<string>::seeEmptyError)
    {
        cout << endl << "ERROR: CANNOT SEE NEXT SINCE THE LIST IS EMPTY" << endl;
    }
    catch (Linkedlist<string >::getEmptyError)
    {
        cout << endl << "ERROR: CANNOT GET IT SINCE THE LIST IS EMPTY" << endl;
    }
    catch (Linkedlist<string>::IsInEmptyError)
    {
        cout << endl << "ERROR: NOT ON THE LIST SINCE THE LIST IS EMPTY" << endl;
    }
    catch (Linkedlist<string>::seeAtError)
    {
        cout << endl << "ERROR: SEE AT LOCATION IS NOT ON THE LIST" << endl;
    }


}
