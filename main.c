#include <stdio.h>
#include "functions.h"
#include "datatypes.h"
int main() {
	loadDataFromFile();
    int choice;
    while (1) {
        showMenu();  // Hien thi menu
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayBooks(); // Hien thi danh sach sach
                break;
            case 2:
                addBook(); // Them sach moi
                break;
            case 3:
        		editBook(); // Sua thong tin sach
                break;
            case 4:
                deleteBook(); // Xoa sach
                break;
            case 5:
            	sortBooksByPrice(); // Sap xep sach tang dan theo gia tien
                break;
            case 6:
            	searchBookByTitle(); // Tim kiem sach
                break;
            case 7:
        		saveDataToFile(); // Luu du lieu vao file
        		break;
    		case 8:
    			saveDataToFile();
        		printf("\nCam on ban da su dung chuong trinh cua minh!\n");
        		return 0;  // Thoat
            default:
                printf("\nLua chon khong hop le. Vui long chon lai.\n");
        }
    }
    return 0;
}
