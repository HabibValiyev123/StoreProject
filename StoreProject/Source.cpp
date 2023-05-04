#include <iostream>
#include <cstring>

using namespace std;

const int MAX_PRODUCTS = 100;

struct Product {
    char name[50];
    double price;
    double discount;
};

struct Store {
    int count;
    Product products[MAX_PRODUCTS];
};

void showAllProducts(const Store& store) {
    cout << "All products in store: " << endl;
    for (int i = 0; i < store.count; i++) {
        cout << "Name: " << store.products[i].name << endl;
        cout << "Price: " << store.products[i].price << endl;
        cout << "Discount: " << store.products[i].discount << endl;
        cout << endl;
    }
}

void addProduct(Store& store) {
    if (store.count == MAX_PRODUCTS) {
        cout << "Store is full, cannot add more products." << endl;
        return;
    }

    Product product;
    cout << "Enter name of product: ";
    cin.getline(product.name, 50);
    cout << "Enter price of product: ";
    cin >> product.price;
    cout << "Enter discount of product: ";
    cin >> product.discount;

    store.products[store.count] = product;
    store.count++;

    cout << "Product added to store." << endl;
}

void deleteProduct(Store& store) {
    char nameToDelete[50];
    cout << "Enter name of product to delete: ";
    cin.getline(nameToDelete, 50);

    for (int i = 0; i < store.count; i++) {
        if (strcmp(store.products[i].name, nameToDelete) == 0) {
            for (int j = i; j < store.count - 1; j++) {
                store.products[j] = store.products[j + 1];
            }
            store.count--;
            cout << "Product deleted from store." << endl;
            return;
        }
    }

    cout << "Product not found in store." << endl;
}

void searchProductByName(const Store& store) {
    char nameToSearch[50];
    cout << "Enter name of product to search: ";
    cin.getline(nameToSearch, 50);

    for (int i = 0; i < store.count; i++) {
        if (strcmp(store.products[i].name, nameToSearch) == 0) {
            cout << "Name: " << store.products[i].name << endl;
            cout << "Price: " << store.products[i].price << endl;
            cout << "Discount: " << store.products[i].discount << endl;
            return;
        }
    }

    cout << "Product not found in store." << endl;
}

int main() {
    Store store = { 0 };

    while (true) {
        cout << "Enter option (1. Show all products, 2. Add new product, 3. Delete product, 4. Search product by name): ";
        int option;
        cin >> option;
        cin.ignore();
        switch (option) {
        case 1:
            showAllProducts(store);
            break;
        case 2:
            addProduct(store);
            break;
        case 3:
            deleteProduct(store);
            break;
        case 4:
            searchProductByName(store);
            break;
        default:
            cout << "Invalid option, please try again." << endl;
            break;
        }

        cout << endl;
    }

    return 0;
}