#include <iostream>
#include <string>
using namespace std;

class Product
{
    string name;
    double price;
    string description;
    bool availability;

public:
    Product(string n, double p, string d, bool a) : name(n), price(p), description(d), availability(a) {}

    double getPrice() const { return price; }
    string getName() const { return name; }
    string getDescription() const { return description; }
    bool isAvailable() const { return availability; }
};

void swap(Product &a, Product &b)
{
    Product temp = a;
    a = b;
    b = temp;
}

int partition(Product arr[], int low, int high)
{
    double pivot = arr[high].getPrice();
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j].getPrice() < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(Product arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void displayProducts(Product arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Product Name: " << arr[i].getName() << endl;
        cout << "Price: $" << arr[i].getPrice() << endl;
        cout << "Description: " << arr[i].getDescription() << endl;
        cout << "Availability: " << (arr[i].isAvailable() ? "In Stock" : "Out of Stock") << endl;
        cout<<endl;
    }
}

int main()
{
    Product products[3] = {
        Product("Lays", 1000, "xys", true),
        Product("cakes", 540, "etry", true),
        Product("biscuits", 3400, "uytuy", false)};

    quickSort(products, 0, 2);

    cout << "Sorted Product List by Price:" << endl;
    displayProducts(products, 3);
}
