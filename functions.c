#include <stdio.h>
#include <string.h>
#include "functions.h"
#include "datatypes.h"
#include <stdlib.h>
struct Book books[100];  
int bookCount = 0; 
int nextBookID = 1; 
// Hien thi Menu
void showMenu() {
	system("cls");
    printf("==== Quan Li Thu Vien Sach ====\n");
    printf("========MENU========\n");
    printf("1. Hien thi danh sach sach\n");
    printf("2. Them sach moi\n");
    printf("3. Sua thong tin sach\n");
    printf("4. Xoa sach\n");
    printf("5. Cap nhat thong tin sach theo gia tien\n");
    printf("6. Tim kiem sach\n");
    printf("7. Luu du lieu\n");
	printf("8. Thoat\n");
    printf("Nhap lua chon cua ban: ");
}
// Quay lai menu chinh
void goBackToMenu() {
    printf("\nNhan phim bat ky de quay lai menu chinh...\n");
    getchar();
    getchar();
}
// Kiem tra du lieu nhap vao co hop le khong
int isValidInput(const struct Book *book) {
    if (strlen(book->title) == 0 || strlen(book->author) == 0) {
        printf("Loi: Ten sach va ten tac gia khong duoc de trong. Ban hay nhap lai nhe\n");
        return 0;
    }
    if (book->year <= 0 || book->price <= 0) {
        printf("Loi: Nam xuat ban va gia sach phai lon hon 0. Ban hay nhap lai nhe\n");
        return 0;
    }
    for (int i = 0; i < bookCount; i++) {
        if (strcmp(books[i].title, book->title) == 0) {
            printf("Loi: Ten sach khong duoc trung nhau. Ban hay nhap lai nhe\n");
            return 0;
        }
    }
    return 1;
}
// Them sach moi
void addBook() {
    system("cls");
    if (bookCount >= 100) {
        printf("Danh sach da day.\n");
        goBackToMenu();
        return;
    }
    printf("\n===== Them Sach Moi =====\n");
    struct Book newBook;
    newBook.id = nextBookID++;  
    printf("Moi ban nhap ten sach: ");
    getchar();  
    fgets(newBook.title, sizeof(newBook.title), stdin);
    newBook.title[strcspn(newBook.title, "\n")] = '\0';
    printf("Nhap tac gia: ");
    fgets(newBook.author, sizeof(newBook.author), stdin);
    newBook.author[strcspn(newBook.author, "\n")] = '\0';
    int validInput = 0;
    while (!validInput) {
        printf("Nhap nam xuat ban: ");
        if (scanf("%d", &newBook.year) == 1 && newBook.year > 0) {
            validInput = 1;
        } else {
            printf("Loi: Vui long nhap so nguyen hop le.\n");
            getchar();  
        }
    }
    validInput = 0;
    while (!validInput) {
        printf("Nhap gia sach: ");
        if (scanf("%d", &newBook.price) == 1 && newBook.price > 0) {
            validInput = 1;
        } else {
            printf("Loi: Vui long nhap so nguyen hop le.\n");
            getchar();  
        }
    }
    if (isValidInput(&newBook)) {
        books[bookCount] = newBook;
        bookCount++;
        printf("Ban da them sach thanh cong!\n");
    }
    goBackToMenu();
}
// Tim kiem sach theo ten (khong phan biet chu hoa, chu thuong)
void searchBookByTitle() {
    system("cls");
    if (bookCount == 0) {
        printf("Khong co sach nao trong danh sach de tim kiem.\n");
        goBackToMenu();
        return;
    }
    char searchTitle[100];
    printf("\n===== Tim Kiem Sach =====\n");
    printf("Nhap ten sach muon tim: ");
    getchar();  
    fgets(searchTitle, sizeof(searchTitle), stdin);
    searchTitle[strcspn(searchTitle, "\n")] = '\0';
    // Chuyen ten sach tim kiem ve chu thuong
    for (int i = 0; searchTitle[i]; i++) {
        searchTitle[i] = tolower(searchTitle[i]);
    }
    printf("\nKet qua tim kiem:\n");
    int found = 0;
    printf("+----+------------------------------+------------------------------+------------+------------+\n");
    printf("| ID | %-28s | %-28s | %-10s | %-10s |\n", "Ten Sach", "Tac Gia", "Nam XB", "Gia");
    printf("+----+------------------------------+------------------------------+------------+------------+\n");
    // Duyet qua danh sach sach va tim kiem
    for (int i = 0; i < bookCount; i++) {
        // Chuyen ten sach trong danh sach ve chu thuong
        char tempTitle[100];
        strcpy(tempTitle, books[i].title);
        for (int j = 0; tempTitle[j]; j++) {
            tempTitle[j] = tolower(tempTitle[j]);
        }
        // Kiem tra ten sach trong danh sach co chua ten sach tim kiem
        if (strstr(tempTitle, searchTitle) != NULL) {
            found = 1;
            printf("| %-2d | %-28s | %-28s | %-10d | %-10d |\n",
                   books[i].id,
                   books[i].title,
                   books[i].author,
                   books[i].year,
                   books[i].price);
        }
    }
    printf("+----+------------------------------+------------------------------+------------+------------+\n");
    if (!found) {
        printf("\nKhong tim thay sach nao phu hop voi tu khoa: %s\n", searchTitle);
    }
    goBackToMenu();
}
// Hien thi danh sach sach
void displayBooks() {
	system("cls");
    if (bookCount == 0) {
        printf("\nChua co sach nao trong danh sach.\n");
        goBackToMenu();
        return;
    }
    printf("\n====== Danh Sach Sach ======\n");
    printf("+----+------------------------------+------------------------------+------------+------------+\n");
    printf("| ID | %-28s | %-28s | %-10s | %-10s |\n", "Ten Sach", "Tac Gia", "Nam XB", "Gia");
    printf("+----+------------------------------+------------------------------+------------+------------+\n");
    for (int i = 0; i < bookCount; i++) {
        printf("| %-2d | %-28s | %-28s | %-10d | %-10d |\n",
               books[i].id,
               books[i].title,
               books[i].author,
               books[i].year,
               books[i].price);
    }
    printf("+----+------------------------------+------------------------------+------------+------------+\n");
    goBackToMenu();
    return;
}
// Sua sach
void editBook() {
    system("cls");
    int id, validInput;
    printf("\n===== Sua thong tin sach =====\n");
    printf("\nNhap ID sach ban muon sua: ");
    while (scanf("%d", &id) != 1) {
        printf("Loi: Vui long nhap so nguyen hop le.\nNhap ID sach ban muon sua: ");
        getchar(); 
    }
    int found = 0;
    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == id) {
            found = 1;
            printf("\nThong tin sach hien tai:\n");
            printf("ID: %d\n", books[i].id);
            printf("Ten sach: %s\n", books[i].title);
            printf("Tac gia: %s\n", books[i].author);
            printf("Nam xuat ban: %d\n", books[i].year);
            printf("Gia: %d\n", books[i].price);
            printf("\nNhap thong tin moi:\n");
            getchar();  
            printf("Moi ban nhap ten sach moi: ");
            fgets(books[i].title, sizeof(books[i].title), stdin);
            books[i].title[strcspn(books[i].title, "\n")] = '\0';
            printf("Nhap tac gia moi: ");
            fgets(books[i].author, sizeof(books[i].author), stdin);
            books[i].author[strcspn(books[i].author, "\n")] = '\0';
            validInput = 0;
            while (!validInput) {
                printf("Moi ban nhap nam xuat ban moi: ");
                if (scanf("%d", &books[i].year) == 1) {
                    validInput = 1;
                } else {
                    printf("Loi: Vui long nhap so nguyen hop le.\n");
                    getchar();
                }
            }
            validInput = 0;
            while (!validInput) {
                printf("Moi ban nhap gia sach moi: ");
                if (scanf("%d", &books[i].price) == 1) {
                    validInput = 1;
                } else {
                    printf("Loi: Vui long nhap so nguyen hop le.\n");
                    getchar();
                }
            }
            printf("\nBan da sua thong tin sach thanh cong!\n");
            goBackToMenu();
            return;
        }
    }
    if (!found) {
        printf("\nKhong tim thay sach voi ID %d.\n", id);
        goBackToMenu();
    }
}
// Xoa sach
void deleteBook() {
    system("cls");
    while (1) {
        printf("\n===== Xoa Sach =====\n");
        if (bookCount == 0) {
            printf("Khong co sach trong danh sach de xoa.\n");
            goBackToMenu();
            return;
        }
        int id;
        printf("Nhap ID sach ban muon xoa: ");
        scanf("%d", &id);  
        int found = 0;     // Bien danh dau sach da tim thay
        for (int i = 0; i < bookCount; i++) {
            if (books[i].id == id) {  // Neu tim thay sach co ID trung
                found = 1;
                printf("\nThong tin sach muon xoa:\n");
                printf("ID: %d\n", books[i].id);
                printf("Ten sach: %s\n", books[i].title);
                printf("Tac gia: %s\n", books[i].author);
                printf("Nam xuat ban: %d\n", books[i].year);
                printf("Gia: %d\n", books[i].price);
                char confirm;
                printf("\nBan co chac chan muon xoa sach nay? (y/n): ");
                getchar();  
                scanf("%c", &confirm);
                if (confirm == 'y' || confirm == 'Y') {
                    for (int j = i; j < bookCount - 1; j++) {
                        books[j] = books[j + 1];  // Di chuyen sach phia sau len
                    }
                    bookCount--;  // Giam so luong sach
                    printf("\nSach da duoc xoa thanh cong!\n");
                    goBackToMenu();
                    return;
                } else {
                    printf("\nHuy thao tac xoa sach.\n");
                    goBackToMenu();
                    return;
                }
            }
        }
        if (!found) {  // Neu khong tim thay sach voi ID da nhap
            printf("\nKhong tim thay sach voi ID %d.\n", id);
            goBackToMenu();
            return;
        }
    }
}
// Sap xep sach theo gia tien
void sortBooksByPrice() {
	system("cls");
    while (1) {
        printf("\n===== Sap Xep Sach Theo Gia =====\n");
        if (bookCount == 0) {
            printf("Khong co sach trong danh sach de sap xep.\n");
            goBackToMenu();
            return;
        }
        printf("\nMoi ban chon thu tu sap xep:\n");
        printf("1. Tang dan\n");
        printf("2. Giam dan\n");
        printf("Nhap lua chon cua ban: ");
        int choice;
        scanf("%d", &choice);
        if (choice == 1 || choice == 2) {
            for (int i = 0; i < bookCount - 1; i++) {
                for (int j = i + 1; j < bookCount; j++) {
                    if ((choice == 1 && books[i].price > books[j].price) ||
                        (choice == 2 && books[i].price < books[j].price)) {
                        struct Book temp = books[i];
                        books[i] = books[j];
                        books[j] = temp;
                    }
                }
            }
            printf("\nBan da sap xep thanh cong!\n");
            displayBooks();
            return;
        } else {
            printf("\nLua chon cua ban khong hop le.\n");
        }
    }
}
// De doc du lieu
void loadDataFromFile() {
    FILE *file = fopen("books_data.bin", "rb"); 
    if (file != NULL) {
        fread(&bookCount, sizeof(int), 1, file);  // Doc so luong sach (bookCount) tu file
        fread(&nextBookID, sizeof(int), 1, file); 
        fread(books, sizeof(struct Book), bookCount, file); 
        fclose(file); 
    } else {
        printf("Khong tim thay file books_data.bin, tao file moi khi luu du lieu.\n");
    }
}
//  De ghi du lieu 
void saveDataToFile() {
    FILE *file = fopen("books_data.bin", "wb"); 
    if (file != NULL) {
        fwrite(&bookCount, sizeof(int), 1, file);  // Ghi so luong sach (bookCount) vao file
        fwrite(&nextBookID, sizeof(int), 1, file); 
        fwrite(books, sizeof(struct Book), bookCount, file); 
        fclose(file); 
        printf("Da luu du lieu thanh cong vao books_data.bin\n");
    } else {
        printf("Khong the mo file de luu du lieu.\n");
    }
}






