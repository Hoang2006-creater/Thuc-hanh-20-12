#include <stdio.h>
#include <string.h>

struct Dish {
    int id;
    char name[100];
    double price;
};

int main() {
    struct Dish menu[100] = {
        {1, "Cut lon sao me", 30.0},
        {2, "Suon xao chua ngot", 50.0},
        {3, "Banh trang nuong", 15.0},
        {4, "Kem", 10.0},
        {5, "Tra sua", 25.0}
    };
    int size = 5;
    int choice;

    do {
        printf("\n     Menu     \n");
        printf("1. In ra cac gia tri co trong menu mon an\n");
        printf("2. Them mot phan tu vao vi tri chi dinh\n");
        printf("3. Sua mot phan tu o vi tri chi dinh\n");
        printf("4. Sap xep cac phan tu tang dan theo price\n");
        printf("5. Tim kiem phan tu theo name nhap vao\n");
        printf("6. Thoat\n");
        printf("Moi ban nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Cac gia tri co trong menu la:\n");
                for (int i = 0; i < size; i++) {
                    printf("%d. %s: %.2f\n", menu[i].id, menu[i].name, menu[i].price);
                }
                break;

            case 2: {
                int pos;
                struct Dish new_dish;
                printf("Nhap vi tri can them (0-%d): ", size);
                scanf("%d", &pos);
                getchar();

                if (pos < 0 || pos > size) {
                    printf("Vi tri khong hop le!\n");
                    break;
                }

                printf("Nhap ID: ");
                scanf("%d", &new_dish.id);
                getchar(); 
                printf("Nhap ten mon an: ");
                fgets(new_dish.name, 100, stdin);
                printf("Nhap gia: ");
                scanf("%lf", &new_dish.price);
                getchar(); 
                for (int i = size; i > pos; i--) {
                    menu[i] = menu[i - 1];
                }
                menu[pos] = new_dish;
                size++;
                printf("Them thanh cong!\n");
                break;
            }

            case 3: {
                int pos;
                printf("Nhap vi tri can sua (0-%d): ", size - 1);
                scanf("%d", &pos);
                getchar(); 
                if (pos < 0 || pos >= size) {
                    printf("Vi tri khong hop le!\n");
                    break;
                }

                printf("Nhap ID moi: ");
                scanf("%d", &menu[pos].id);
                getchar(); 

                printf("Nhap ten mon an moi: ");
                fgets(menu[pos].name, 100, stdin);
                menu[pos].name[strcspn(menu[pos].name, "\n")] = '\0'; 

                printf("Nhap gia moi: ");
                scanf("%lf", &menu[pos].price);
                getchar(); 

                printf("Sua thanh cong!\n");
                break;
            }

            case 4: {
                for (int i = 0; i < size - 1; i++) {
                    for (int j = i + 1; j < size; j++) {
                        if (menu[i].price > menu[j].price) {
                            struct Dish temp = menu[i];
                            menu[i] = menu[j];
                            menu[j] = temp;
                        }
                    }
                }
                printf("Sap xep thanh cong!\n");
                break;
            }

            case 5: {
                char search_name[100];
                printf("Nhap ten mon an can tim: ");
                getchar(); 
                fgets(search_name, 100, stdin);
                search_name[strcspn(search_name, "\n")] = '\0'; 

                int found = 0;
                for (int i = 0; i < size; i++) {
                    if (strcmp(menu[i].name, search_name) == 0) {
                        printf("Tim thay: %d. %s: %.2f\n", menu[i].id, menu[i].name, menu[i].price);
                        found = 1;
                    }
                }
                if (!found) {
                    printf("Khong tim thay mon an!\n");
                }
                break;
            }

            case 6:
                printf("Thoat chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (choice != 6);

    return 0;
}

