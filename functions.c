#include <stdio.h>
#include <string.h>
#include "functions.h"
// Hien thi menu
void displayMenu() {
    printf("=== HE THONG QUAN LY KHACH HANG ===\n");
    printf("1. Xem danh sach khach hang\n");
    printf("2. Them khach hang\n");
    printf("3. Sua thong tin khach hang\n");
    printf("4. Khoa/Mo khoa khach hang\n");
    printf("5. Tim kiem khach hang theo ten\n");
    printf("6. Cho khach hang muon sach\n");
    printf("7. Tra lai sach da muon\n");
    printf("8. Luu tru du lieu\n");
    printf("9. Thoat\n");
    printf("Nhap lua chon: ");
}
// Hien thi danh sach khach hang
void displayCustomerList(struct Customer customers[], int customerCount) {
    if (customerCount == 0) {
        printf("Khong co khach hang.\n");
        return;
    }
    printf("Danh sach khach hang:\n");
    for (int i = 0; i < customerCount; i++) {
        printf("ID: %d, Ten: %s, Dia chi: %s, Trang thai: %s\n", 
               customers[i].id, customers[i].name, customers[i].address, 
               (customers[i].status == 0 ? "Active" : "Blocked"));
    }
}
int getMenuChoice() {
    int choice;
    while (1) {
        if (scanf("%d", &choice) != 1) { // Kiem tra du lieu nhap vao
            printf("Vui long nhap mot so.\n");
            while (getchar() != '\n');  // Doc bo cac ky tu thua
            continue;
        }
        if (choice < 1 || choice > 9) {
            printf("Lua chon khong hop le. Vui long nhap lai: ");
        } else {
            break;
        }
    }
    return choice;
}
// Sua thong tin khach hang
void editCustomer(struct Customer customers[], int customerCount) {
    int id;
    printf("Nhap id khach hang muon sua: ");
    scanf("%d", &id);
    // Tim khach hang theo ID
    int found = 0;
    for (int i = 0; i < customerCount; i++) {
        if (customers[i].id == id) {
            printf("Thong tin hien tai: ID: %d, Ten: %s, Dia chi: %s\n", 
                   customers[i].id, customers[i].name, customers[i].address);
            printf("Nhap ten moi: ");
            getchar();
            fgets(customers[i].name, 100, stdin);
            customers[i].name[strcspn(customers[i].name, "\n")] = 0;
            printf("Nhap dia chi moi: ");
            fgets(customers[i].address, 200, stdin);
            customers[i].address[strcspn(customers[i].address, "\n")] = 0;
            printf("Khach hang da duoc sua thong tin.\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Khach hang voi ID %d khong ton tai.\n", id);
    }
}



