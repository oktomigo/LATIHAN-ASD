#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};
struct node *head;

void awal(){
    struct node *ptr;
    int item;

    ptr = (struct node*) malloc(sizeof(struct node*));
    if (ptr==NULL)
    {
        printf("Overflow!");
    }else{
        printf("Masukan data : ");
        scanf("%d", &item);
        ptr->data = item;
        ptr->next = head;
        head = ptr;
        printf("Data berhasil disimpan di bagian awal!");
    }
}

void akhir(){
    struct node *ptr, *temp;
    int item;

    ptr = (struct node*) malloc(sizeof(struct node*));
    if (ptr==NULL){
        printf("Overflow!");
    }else{
        printf("Masukan data : ");
        scanf("%d", &item);
        ptr->data = item;
        if(head==NULL){
            ptr->next = NULL;
            head = ptr;
            printf("Berhasil menyimpan DATA!");
        }else{
            temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->next = NULL;
            printf("Berhasil simpan DATA akhir !");
        }
    }

}

void sembarang(){
    struct node *ptr, *temp;
    int item, lokasi;

    ptr = (struct node*) malloc(sizeof(struct node*));
    if (ptr==NULL){
        printf("Overflow!");
    }else{
        printf("Masukan data : ");
        scanf("%d", &item);
        ptr->data = item;
        printf("Anda mau menyimpan data dilokasi berapa? ");
        scanf("%d", &lokasi);
        temp = head;
        for(int i=0; i<lokasi; i++){
            temp = temp->next;
            if(temp==NULL){
                printf("Tidak bisa menyimpan data yang anda inputkan!");
                return;
            }
        }
        ptr->next = temp->next;
        temp->next = ptr;
        printf("DATA berhasil disimpan");
    }
}

void cetak(){
    struct node *ptr;
    ptr = head;
    if(ptr==NULL){
        printf("Listnya kosong nih isi dong!!!");
    }else{
        printf("Cetak isi list .... ");
        while(ptr != NULL){
            printf("\n %d", ptr->data);
            ptr = ptr->next;
        }printf("\n ");
    }
}

void hapusawal(){
    system("cls");
    struct node *ptr;
    if(head == NULL){
        printf("List kosong bro!\n");
    }else{
        ptr = head;
        head = ptr->next;
        free(ptr);
        printf("NODE awal berhasil dihapus!");
    }
}

void hapusakhir(){
    system("cls");
    struct node *ptr,*temp;
    char *data;
    if(head == NULL){
        printf("List kosong bro!\n");
    }else{
        if (head->next != NULL) {
            temp = head;
            while(temp->next->next != NULL) {
                temp = temp->next;
            }
            ptr = temp->next;
            data = ptr->data;
            temp->next = NULL;
            free(ptr);
        } else {
            data = head->data;
            head = NULL;
        }
        printf("NODE akhir berhasil dihapus!");
    }
}

void hapussembarang(){
    system("cls");
    struct node *ptr,*temp,*temp2;
    char *data1;
    if(head == NULL){
        printf("List kosong bro!\n");
    }else{
        if (head->next != NULL) {
            temp = head;
            while(temp->next->next != NULL) {
                temp = temp->next;
            }
            ptr = temp->next;
            data1 = ptr->data;
            temp->next = NULL;
            free(ptr);
        } else {
            data1 = head->data;
            head = NULL;
        }
        printf("NODE sembarang berhasil dihapus!");
    }
}

void hapus(){
    int pilih;
    do{
        system("cls");
        printf("====================================");
        printf("\n===== Menu latihan LINKED LIST =====");
        printf("\n====================================");
        printf("\n1.Hapus data diawal \n2.Hapus data di akhir \n3.Hapus data sembarang  \n4.Keluar\n");
        printf("\nPilihanmu ? ");
        scanf("%d", &pilih);

        switch(pilih){
            case 1 :hapusawal();
                getch();
                break;
            case 2 :hapusakhir();
                getch();
                break;
            case 3 :hapussembarang();getch();break;
            case 4 :main();break;
            default:
                printf("Menu yang anda input tidak terdaftar, Silahkan masukan kembali input dengan benar!\n");
        }
    }while(pilih!=4);
}

void main(){
   int pilihan;

   while(pilihan != 6 ){
       system("cls");
       printf("\n====================================");
       printf("\n===== Menu latihan LINKED LIST =====");
       printf("\n====================================");
       printf("\n1.Input  data diawal \n2.Input data di akhir \n3.Input data sembarang \n4.lihat data \n5.hapus data\n6.Keluar\n");
       printf("\nPilihanmu ? ");
       scanf("%d", &pilihan);

       switch(pilihan)
       {
           case 1 :system("cls");awal();getch();break;
           case 2 :system("cls");akhir();getch();break;
           case 3 :system("cls");sembarang();getch();break;
           case 4 :system("cls");cetak();getch();break;
           case 5 :system("cls");hapus();getch();break;
           case 6 :exit(0);break;
           default:
               printf("Menu yang anda input tidak terdaftar, Silahkan masukan kembali input dengan benar!\n");
       }
   }
}
