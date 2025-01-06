#include <stdio.h>
#include "functions.h"
int main() {
    struct Customer customers[100];  // Gioi han toi da 100 khach hang
    int customerCount = 0;
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                displayCustomerList(customers, customerCount);
                break;
            case 2:
                break;
            case 3:
                editCustomer(customers, customerCount);
                break;
            case 4:
                break;
            case 5:
                break;
			case 6:
                break;
			case 7:
                break;
			case 8:               
                break;    
            case 9:
                printf("Thoat chuong trinh. Cam on ban da su dung chuong trinh cua minh nhe!\n");
                return 0;
            default:
                printf("Lua chon khong hop le. Vui long ban hay nhap lai.\n");
        }
    }
}
