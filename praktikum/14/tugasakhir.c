// include library
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node *ptrnode;
// struct main
struct data
{
    char nama[20];
    int umur;
    char sex[20];
    char phone[20];
    char email[40];
    struct node *next;
};
// struct stack redo
struct redo
{
    int data;
    struct node *next;
};
// struct stack undo
struct undo
{
    int data;
    struct node *next;
};
// struct stack temp
struct stack
{
    char nama[20];
    int umur;
    char sex[20];
    char phone[20];
    char email[40];
    struct node *next;
};
// Cari Berdasar Nama
ptrnode carinama(struct data *head, char nama[20])
{
    struct data *current = head->next;
    while (current != NULL)
    {
        if (strcmp(current->nama, nama) == 0)
        {
            return current;
        }
        current = current->next;
    }
}
// Cari Berdasar Umur
ptrnode carinomor(char nomor[20], struct data *head)
{
    struct data *current = head->next;

    while (current != NULL)
    {
        if (strcmp(current->phone, nomor) == 0)
        {
            return current;
        }
        current = current->next;
    }
}
// cari berdasar email
ptrnode cariemail(char email[40], struct data *head)
{
    struct data *current = head->next;

    while (current != NULL)
    {
        if (strcmp(current->email, email) == 0)
        {
            return current;
        }
        current = current->next;
    }
}
// cari menu
ptrnode carimenu(struct data *head)
{
    char nama[20];
    char phone[20];
    char email[40];
    printf("\n");
    printf("======================================\n");
    printf("            Cari Berdasar ?\n");
    printf("======================================\n");
    struct data *current = head->next;
    int cari;
    printf("\t1.Nama\n");
    printf("\t2.Nomor Telephone\n");
    printf("\t3.Email\n");
    printf("\t4.Kembali\n");
    printf("======================================\n");
    printf("\tPilihan Anda : ");
    scanf("%d", &cari);
    printf("======================================\n");
    switch (cari)
    {
    case 1:
        printf("Masukkan Nama : ");
        getchar();
        scanf("%[^\n]s", &nama);
        current = carinama(head, nama);
        break;
    case 2:
        printf("Masukkan Nomor : ");
        scanf("%s", phone);
        current = carinomor(phone, head);
        break;
    case 3:
        printf("Masukkan Email : ");
        scanf("%s", email);
        current = cariemail(email, head);
        break;
    case 4:
        return;
    default:
        printf("Pilihan tidak ada\n");
        break;
    }
    if (current != NULL)
    {
        printf("======================================\n");
        printf("           Data Ditemukan\n");
        printf("======================================\n");
        printf("\tNama    : %s\n", current->nama);
        printf("\tUmur    : %d\n", current->umur);
        printf("\tSex     : %s\n", current->sex);
        printf("\tTelepon : %s\n", current->phone);
        printf("\tEmail   : %s\n", current->email);
        printf("======================================\n");
    }
    else
    {
        printf("======================================\n");
        printf("            Data not found\n");
        printf("======================================\n");
    }
    system("pause");
    return current;
}
// insert menu
void insertmenu(struct data *head)
{
    char nama[20];
    int umur;
    char sex[20];
    char phone[20];
    char email[40];
    printf("\n======================================\n");
    printf("             Masukkan Data ! \n");
    printf("======================================\n");
    printf("\tNama        : ");
    getchar();
    scanf("%[^\n]s", &nama);
    getchar();
    printf("\tUmur        : ");
    scanf("%d", &umur);
    getchar();
    printf("\tSex (L/P)   : ");
    scanf("%s", &sex);
    printf("\tPhone       : ");
    scanf("%s", &phone);
    printf("\temail       : ");
    scanf("%s", &email);
    insertdata(head, nama, umur, sex, phone, email);
    printf("======================================\n");
    printf("        Data Berhasil Disimpan\n");
    printf("======================================\n");
    system("pause");
}
// insert data
void insertdata(struct data *head, char nama[20], int umur, char sex[20], char phone[20], char email[40])
{
    struct data *newdata = (struct data *)malloc(sizeof(struct data));
    strcpy(newdata->nama, nama);
    newdata->umur = umur;
    strcpy(newdata->sex, sex);
    strcpy(newdata->phone, phone);
    strcpy(newdata->email, email);
    newdata->next = head->next;
    head->next = newdata;
}
// print all
void print(struct data *head)
{
    struct data *current = head->next;
    if (current == NULL)
    {
        printf("\nData Kosong\n");
        system("pause");
        return;
    }
    printf("\n===============================================");
    printf("===============================================\n");
    printf("\tNama \t|\t Umur\t|\t Sex\t|\t Phone\t|\t Email\n");
    printf("===============================================");
    printf("===============================================\n");
    while (current != NULL)
    {
        printf("   %s\t %d\t\t %s\t %s\t      %s\n", current->nama, current->umur, current->sex, current->phone, current->email);
        current = current->next;
    }
    printf("\n\n===============================================");
    printf("===============================================\n");
    system("pause");
}
// delete berdasar nama
ptrnode deletenama(struct data *head, char nama[20])
{
    struct data *previous = head;
    struct data *current = head->next;
    while (current != NULL)
    {
        if (strcmp(current->nama, nama) == 0)
        {
            previous->next = current->next;

            return current;
        }
        previous = current;
        current = current->next;
    }
}
// delete berdasar nomor
ptrnode deletenomor(struct data *head, char nomor[20])
{
    struct data *previous = head;
    struct data *current = head->next;
    while (current != NULL)
    {
        if (strcmp(current->phone, nomor) == 0)
        {
            previous->next = current->next;
            return current;
        }
        previous = current;
        current = current->next;
    }
}
// delete berdasar email
ptrnode deleteemail(struct data *head, char email[40])
{
    struct data *previous = head;
    struct data *current = head->next;
    while (current != NULL)
    {
        if (strcmp(current->email, email) == 0)
        {
            previous->next = current->next;
            return current;
        }
        previous = current;
        current = current->next;
    }
}
// delete menu
ptrnode deletemenu(struct data *head, struct stack *high)
{
    int pilih;
    printf("\n======================================\n");
    printf("\tDelete Berdasar ? \n");
    printf("======================================\n");
    printf("\t1.Nama\n");
    printf("\t2.Nomor\n");
    printf("\t3.Email\n");
    printf("\t4.Kembali\n");
    printf("======================================\n");
    printf("\tPilihan Anda : ");
    scanf("%d", &pilih);
    printf("======================================\n");
    struct data *current = head->next;
    switch (pilih)
    {
    case 1:
        printf("Masukkan Nama : ");
        char nama[20];
        getchar();
        scanf("%[^\n]s", &nama);
        current = deletenama(head, nama);
        break;
    case 2:
        printf("Masukkan Nomor : ");
        char nomor[20];
        scanf("%s", nomor);
        current = deletenomor(head, nomor);
        break;
    case 3:
        printf("Masukkan Email : ");
        char email[40];
        scanf("%s", email);
        current = deleteemail(head, email);
        break;
    case 4:
        return;
    default:
        printf("Pilihan tidak ada\n");
        break;
    }
    if (current != NULL)
    {
        insertstack(current, high);
        free(current);
        printf("======================================\n");
        printf("\tData berhasil dihapus\n");
        printf("======================================\n");
    }
    else
    {
        printf("======================================\n");
        printf("\tData not found\n");
        printf("======================================\n");
    }
    system("pause");
}
// Edit
void editmenu(struct data *head, struct stack *high)
{
    int pilih;
    struct data *current = carimenu(head);
    if (current != NULL)
    {
        insertstack(current, high);
        printf("\n======================================\n");
        printf("\t\tEdit ? \n");
        printf("======================================\n");
        printf("\t1.Nama Saja\n");
        printf("\t2.Umur Saja\n");
        printf("\t3.Jenis Kelamin Saja\n");
        printf("\t4.Nomor Telephone Saja\n");
        printf("\t5.Email Saja\n");
        printf("\t6.Update Semua\n");
        printf("\t7.Kembali\n");
        printf("======================================\n");
        printf("Pilihan Anda : ");
        scanf("%d", &pilih);
        printf("======================================\n");
        switch (pilih)
        {
        case 1:
            printf("Update Nama : ");
            getchar();
            scanf("%[^\n]s", &current->nama);
            break;
        case 2:
            printf("Update Umur : ");
            scanf("%d", &current->umur);
            break;
        case 3:
            printf("Update Jenis Kelamin : ");
            scanf("%s", current->sex);
            break;
        case 4:
            printf("Update Nomor Telephone : ");
            scanf("%s", current->phone);
            break;
        case 5:
            printf("Update Email : ");
            scanf("%s", current->email);
            break;
        case 6:
            printf("Update Nama     : ");
            getchar();
            scanf("%[^\n]s", &current->nama);
            printf("Update Umur     : ");
            scanf("%d", &current->umur);
            printf("Update Jenis Kelamin   : ");
            scanf("%s", current->sex);
            printf("Update Nomor Telephone : ");
            scanf("%s", current->phone);
            printf("Update Email    : ");
            scanf("%s", current->email);
            break;
        case 7:
            return;
        default:
            printf("Pilihan tidak ada\n");
            break;
        }
    }
    printf("======================================\n");
    system("pause");
}
// swap sort
swap(struct data *head, struct data *current, struct data *min)
{
    int temp_umur = current->umur;
    char temp_nama[20];
    strcpy(temp_nama, current->nama);
    char temp_sex[20];
    strcpy(temp_sex, current->sex);
    char temp_phone[20];
    strcpy(temp_phone, current->phone);
    char temp_email[20];
    strcpy(temp_email, current->email);

    strcpy(current->nama, min->nama);
    strcpy(current->sex, min->sex);
    strcpy(current->phone, min->phone);
    strcpy(current->email, min->email);
    current->umur = min->umur;

    min->umur = temp_umur;
    strcpy(min->nama, temp_nama);
    strcpy(min->sex, temp_sex);
    strcpy(min->phone, temp_phone);
    strcpy(min->email, temp_email);
}
// sort umur
void sortumur(struct data *head)
{
    struct data *current = head->next;
    struct data *min;
    struct data *temp;
    while (current != NULL)
    {
        min = current;
        temp = current->next;
        while (temp != NULL)
        {
            if (temp->umur < min->umur)
            {
                min = temp;
            }
            temp = temp->next;
        }
        if (min != current)
        {
            swap(head, current, min);
        }
        current = current->next;
    }
}
// sor tnama
void sortnama(struct data *head)
{
    struct data *current = head->next;
    struct data *min;
    struct data *temp;
    while (current != NULL)
    {
        min = current;
        temp = current->next;
        while (temp != NULL)
        {
            if (strcmp(temp->nama, min->nama) < 0)
            {
                min = temp;
            }
            temp = temp->next;
        }
        if (min != current)
        {
            swap(head, current, min);
        }
        current = current->next;
    }
}
// sort nomor telephone
void sortphone(struct data *head)
{
    struct data *current = head->next;
    struct data *min;
    struct data *temp;
    while (current != NULL)
    {
        min = current;
        temp = current->next;
        while (temp != NULL)
        {
            if (strcmp(temp->phone, min->phone) < 0)
            {
                min = temp;
            }
            temp = temp->next;
        }
        if (min != current)
        {
            swap(head, current, min);
        }
        current = current->next;
    }
}
// sort email
void sortemail(struct data *head)
{
    struct data *current = head->next;
    struct data *min;
    struct data *temp;
    while (current != NULL)
    {
        min = current;
        temp = current->next;
        while (temp != NULL)
        {
            if (strcmp(temp->email, min->email) < 0)
            {
                min = temp;
            }
            temp = temp->next;
        }
        if (min != current)
        {
            swap(head, current, min);
        }
        current = current->next;
    }
}
// sort menu
void sortmenu(struct data *head)
{
    int pilih;
    printf("\n======================================\n");
    printf("\tSort Berdasar ? \n");
    printf("======================================\n");
    printf("\t1.Nama\n");
    printf("\t2.Umur\n");
    printf("\t3.Nomor Telephone\n");
    printf("\t4.Email\n");
    printf("\t5.Kembali\n");
    printf("======================================\n");
    printf("\tPilihan Anda : ");
    scanf("%d", &pilih);
    printf("======================================\n");
    switch (pilih)
    {
    case 1:
        sortnama(head);
        break;
    case 2:
        sortumur(head);
        break;
    case 3:
        sortphone(head);
        break;
    case 4:
        sortemail(head);
        break;
    case 5:
        return;
    default:
        printf("Pilihan tidak ada\n");
        break;
    }
    system("pause");
}
// save as
void save(struct data *head)
{
    char save[20];
    struct data *current = head->next;
    printf("\n");
    printf("======================================\n");
    printf("            Save File\n");
    printf("======================================\n");
    printf("Save file as (ex:output.csv) : ");
    getchar();
    scanf("%[^\n]s", &save);
    if (current == NULL)
    {
        printf("Data Kosong\n");
    }
    else
    {
        FILE *file;
        file = fopen(save, "w");
        while (current != NULL)
        {
            fprintf(file, "%s;%d;%s;%s;%s\n", current->nama, current->umur, current->sex, current->phone, current->email);
            current = current->next;
        }
        printf("======================================\n");

        printf("File %s Berhasil Dicetak... \n", save);
        fclose(file);
    }
    system("pause");
}
// load data + insert
const char *getfield(char *line, struct data *head)
{
    char nama[20];
    int umur;
    char sex[20];
    char phone[20];
    char email[40];
    int i = 1;
    const char *tok;
    for (tok = strtok(line, ";"); tok && *tok; tok = strtok(NULL, ";\n"))
    {
        if (i == 1)
        {
            strcpy(nama, tok);
        }
        else if (i == 2)
        {
            umur = atoi(tok);
        }
        else if (i == 3)
        {
            strcpy(sex, tok);
        }
        else if (i == 4)
        {
            strcpy(phone, tok);
        }
        else if (i == 5)
        {
            strcpy(email, tok);
            insertdata(head, nama, umur, sex, phone, email);
        }
        i++;
    }
    return NULL;
}
// load data
void insertload(struct data *head)
{
    char load[20];
    printf("\n======================================\n");
    printf("             Load Data \n");
    printf("======================================\n\n");
    printf("Pastikan format data seperti berikut:\n\n");
    printf("nama;umur;sex;phone;email\n");
    printf("nama;umur;sex;phone;email\n\n");
    printf("======================================");
    printf("\n\tNama file yang akan \ndi load (ex:alhamdulillah.csv)  : ");
    getchar();
    scanf("%[^\n]s", &load);
    printf("======================================\n");
    FILE *stream = fopen(load, "r");
    char line[1024];
    while (fgets(line, 1024, stream))
    {
        char *tmp = strdup(line);
        getfield(tmp, head);
        free(tmp);
    }
    if (stream)
    {
        fclose(stream);
        printf("Data Berhasil di load...\n");
    }
    else
    {
        printf("\tFile tidak ditemukan !!!\n");
    }
    system("pause");
}
// maximal and minimal umur
void maxmin(struct data *head)
{
    struct data *current = head->next;
    int max = 0;
    int min = 9999999;
    while (current != NULL)
    {
        if (current->umur > max)
        {
            max = current->umur;
        }
        if (current->umur < min)
        {
            min = current->umur;
        }
        current = current->next;
    }
    if ((max == 0) || (min == 9999999))
    {
        printf("======================================\n");
        printf("\tData Kosong\n");
        printf("======================================\n");
    }
    else
    {
        printf("======================================\n");
        printf("\tUmur Tertinggi : %d\n", max);
        printf("\tUmur Terendah  : %d\n", min);
        printf("======================================\n");
    }
    system("pause");
}
// average umur
void average(struct data *head)
{
    float count = 0;
    float total = 0;
    struct data *current = head->next;
    while (current != NULL)
    {
        total += current->umur;
        count++;
        current = current->next;
    }
    printf("======================================\n");
    printf("\tRata-rata umur : %0.2f\n", total / count);
    printf("======================================\n");
    system("pause");
}
// push stack undo
void index(struct undo *top, int data)
{
    struct undo *temp = (struct undo *)malloc(sizeof(struct undo));
    temp->data = data;
    temp->next = top->next;
    top->next = temp;
}
// pop stack undo
void deletetop(struct undo *top)
{
    struct undo *previous = top;
    struct undo *current = top->next;
    previous->next = current->next;
    free(current);
}
// undo menu
void undo(struct undo *top, struct data *head, struct stack *high, struct redo *pot)
{

    struct undo *current = top->next;
    if (current == NULL)
    {
        return;
    }
    if (current->data == 1)
    {

        deletehead(head, high);
        insertredo(pot, 1);
    }
    else if (current->data == 2)
    {
        inserthead(head, high);
        insertredo(pot, 2);
    }
    else if (current->data == 3)
    {
        deletehead(head, high);
        // deletestack(high);
        deletetop(top);
        inserthead(head, high->next);
        insertredo(pot, 3);

        return;
    }
    deletetop(top);
}
// redo menu
void redo(struct undo *top, struct data *head, struct stack *high, struct redo *pot)
{

    struct redo *current = pot->next;
    if (current == NULL)
    {
        return;
    }
    if (current->data == 2)
    {

        deletehead(head, high);
        deleteredo(pot);
        index(top, 2);
    }
    else if (current->data == 1)
    {
        inserthead(head, high);
        deleteredo(pot);
        index(top, 1);
    }
    else if (current->data == 3)
    {
        deletehead(head, high);
        deletetop(pot);
        inserthead(head, high->next);
        index(top, 3);
    }
}
// push stack redo
void insertredo(struct redo *pot, int data)
{
    struct redo *temp = (struct redo *)malloc(sizeof(struct redo));
    temp->data = data;
    temp->next = pot->next;
    pot->next = temp;
}
// pop stack redo
void deleteredo(struct redo *pot)
{
    struct redo *previous = pot;
    struct redo *current = pot->next;
    previous->next = current->next;
    free(current);
}
// push stack temp
void insertstack(struct stack *head, struct stack *high)
{
    struct data *newdata = (struct data *)malloc(sizeof(struct data));
    strcpy(newdata->nama, head->nama);
    newdata->umur = head->umur;
    strcpy(newdata->sex, head->sex);
    strcpy(newdata->phone, head->phone);
    strcpy(newdata->email, head->email);
    newdata->next = high->next;
    high->next = newdata;
}
// pop stack temp
void deletestack(struct stack *high)
{
    struct data *previous = high;
    struct data *current = high->next;
    previous->next = current->next;
    free(current);
}
// insert head
void inserthead(struct stack *head, struct stack *high)
{
    struct stack *current = high->next;
    insertdata(head, current->nama, current->umur, current->sex, current->phone, current->email);
    deletestack(high);
}
// delete head
void deletehead(struct data *head, struct stack *high)
{
    struct data *previous = head;
    struct data *current = head->next;
    previous->next = current->next;
    insertstack(current, high);
    free(current);
}
// search and
void carimenuand(struct data *head)
{
    char nama1[20];
    char nomor1[20];
    char email1[20];
    char kosong[] = "0";
    printf("\n");
    printf("======================================\n");
    printf("               Cari (AND) \n");
    printf("======================================\n");
    printf("*Isi dengan angka 0 jika tidak ingin \nmencari dengan variabel tertentu\n");
    printf("======================================\n");
    struct data *current = head->next;
    printf("Masukkan Nama : ");
    getchar();
    scanf("%[^\n]s", &nama1);
    printf("Masukkan Nomor : ");
    scanf("%s", nomor1);
    printf("Masukkan Email : ");
    scanf("%s", email1);
    if ((strcmp(nama1, kosong) == 0) && (strcmp(nomor1, kosong) == 0) && (strcmp(email1, kosong) == 0))
    {
        printf("======================================\n");
        printf("            Data not found\n");
        printf("======================================\n");
        system("pause");
        return NULL;
    }
    while (current != NULL)
    {

        if (((strcmp(current->nama, nama1) == 0) || (strcmp(nama1, kosong) == 0)) &&
            ((strcmp(current->phone, nomor1) == 0) || (strcmp(nomor1, kosong) == 0)) &&
            ((strcmp(current->email, email1) == 0) || (strcmp(email1, kosong) == 0)))
        {
            break;
        }
        current = current->next;
    }
    if (current != NULL)
    {
        printf("======================================\n");
        printf("           Data Ditemukan\n");
        printf("======================================\n");
        printf("\tNama    : %s\n", current->nama);
        printf("\tUmur    : %d\n", current->umur);
        printf("\tSex     : %s\n", current->sex);
        printf("\tTelepon : %s\n", current->phone);
        printf("\tEmail   : %s\n", current->email);
        printf("======================================\n");
    }
    else
    {
        printf("======================================\n");
        printf("            Data not found\n");
        printf("======================================\n");
    }
    system("pause");
    return current;
}
// search or
void carimenuor(struct data *head)
{
    char nama1[20];
    char nomor1[20];
    char email1[20];
    char kosong[] = "0";
    // printf("%s", kosong);
    printf("\n");
    printf("======================================\n");
    printf("               Cari (OR) \n");
    printf("======================================\n");
    printf("*Isi dengan angka 0 jika tidak ingin \nmencari dengan variabel tertentu\n");
    printf("======================================\n");
    struct data *current = head->next;
    printf("Masukkan Nama : ");
    getchar();
    scanf("%[^\n]s", &nama1);
    printf("Masukkan Nomor : ");
    scanf("%s", nomor1);
    printf("Masukkan Email : ");
    scanf("%s", email1);
    if ((strcmp(nama1, kosong) == 0) && (strcmp(nomor1, kosong) == 0) && (strcmp(email1, kosong) == 0))
    {
        printf("======================================\n");
        printf("            Data not found\n");
        printf("======================================\n");
        system("pause");
        return NULL;
    }
    while (current != NULL)
    {

        if (((strcmp(current->nama, nama1) == 0) || (strcmp(nama1, kosong) == 0)) ||
            ((strcmp(current->phone, nomor1) == 0) || (strcmp(nomor1, kosong) == 0)) ||
            ((strcmp(current->email, email1) == 0) || (strcmp(email1, kosong) == 0)))
        {
            if ((strcmp(current->nama, nama1) == 0) ||
                (strcmp(current->phone, nomor1) == 0) ||
                (strcmp(current->email, email1) == 0))
            {
                break;
            }
        }
        current = current->next;
    }

    if (current != NULL)
    {
        printf("======================================\n");
        printf("           Data Ditemukan\n");
        printf("======================================\n");
        printf("\tNama    : %s\n", current->nama);
        printf("\tUmur    : %d\n", current->umur);
        printf("\tSex     : %s\n", current->sex);
        printf("\tTelepon : %s\n", current->phone);
        printf("\tEmail   : %s\n", current->email);
        printf("======================================\n");
    }
    else
    {
        printf("======================================\n");
        printf("            Data not found\n");
        printf("======================================\n");
    }
    system("pause");
    return current;
}
// switch pilih
void pilihan(int n, struct data *head, struct undo *top, struct stack *high, struct redo *pot)
{
    char nama[20];
    int umur;
    char sex[20];
    char phone[20];
    char email[40];
    struct data *current = head->next;
    switch (n)
    {
    case 1:
        carimenu(head);
        break;
    case 2:
        insertmenu(head);
        index(top, 1);
        break;
    case 3:
        print(head);
        break;
    case 4:
        deletemenu(head, high);
        index(top, 2);
        break;
    case 5:
        editmenu(head, high);
        index(top, 3);
        break;
    case 6:
        sortmenu(head);
        break;
    case 7:
        save(head);
        break;
    case 8:
        insertload(head);
        break;
    case 9:
        maxmin(head);
        break;
    case 10:
        maxmin(head);
        break;
    case 11:
        average(head);
        break;
    case 12:
        undo(top, head, high, pot);
        break;
    case 13:
        redo(top, head, high, pot);
        break;
    case 14:
        carimenuand(head);

        break;
    case 15:
        carimenuor(head);
        break;
    case 16:
        // cektop(top);
        break;
    case 17:
        break;
    case 18:
        printf("\nThanks for using this program\n");
        system("pause");
        break;
    default:
        printf("\n\t\tWrong Input\n");
        break;
    }
}
// menu text
void menu()
{
    system("cls");
    printf("\n");
    printf("======================================\n");
    printf("\t\tMENU\n");
    printf("======================================\n");
    printf("\t 1.Search\n");
    printf("\t 2.Insert\n");
    printf("\t 3.View All\n");
    printf("\t 4.Delete\n");
    printf("\t 5.Edit\n");
    printf("\t 6.Sorting\n");
    printf("\t 7.Save File\n");
    printf("\t 8.Load File\n");
    printf("\t 9.Maximum\n");
    printf("\t 10.Minimum\n");
    printf("\t 11.Average\n");
    printf("\t 12.Undo\n");
    printf("\t 13.Redo\n");
    printf("\t 14.Search (And)\n");
    printf("\t 15.Search (Or)\n");
    // printf("\t 16.Wildcard Search\n");
    // printf("\t 17.Konektivitas\n");
    printf("\t 18.Exit\n");
    printf("======================================\n");
}
// main function
int main()
{
    struct data *head = (struct data *)malloc(sizeof(struct data));
    struct undo *top = (struct undo *)malloc(sizeof(struct undo));
    struct undo *pot = (struct undo *)malloc(sizeof(struct undo));
    struct stack *high = (struct stack *)malloc(sizeof(struct stack));
    pot->next = NULL;
    high->next = NULL;
    top->next = NULL;
    head->next = NULL;
    int pilih;
    while (pilih != 18)
    {
        menu();
        printf("\t Pilih Menu : ");
        scanf("%d", &pilih);
        system("cls");
        pilihan(pilih, head, top, high, pot);
    }
}
// end of program