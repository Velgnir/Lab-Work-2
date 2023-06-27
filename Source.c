#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Zaznam {
    long long ID_cislo_mer_osoby;
    char name[31];
    char Mer_modu[4];
    char Typ_mer_veliciny[3];
    double Hodnota;
    int Cas;
    long Datum;
    struct Zaznam* next;
}Zaznam;

Zaznam* n(Zaznam** head) {
    FILE* f;
    Zaznam* help = NULL;
    char b = ' ';
    int count = 0;
    if ((f = fopen("dataloger_V2.txt", "r")) == NULL)
        printf("Zaznamy neboli nacitane!");
    else {
        while (b != EOF) {
            b = getc(f);
            if (b == '$') {
                b = getc(f);
                b = getc(f);
                ++count;
            }
        }
        rewind(f);
        help = (Zaznam*)malloc(sizeof(Zaznam) * count);
        Zaznam* help2 = NULL;
        Zaznam* help3 = help;
        for (int i = 0; i < count; ++i) {
            help2 = NULL;
            help2 = (Zaznam*)malloc(sizeof(Zaznam));
            getc(f);
            getc(f);
            getc(f);
            getc(f);
            fscanf(f, "%lli", &help2->ID_cislo_mer_osoby);
            if ((b = getc(f)) == ' ') {
                getc(f);
            }
            fgets(help2->name, 30, f);
            //printf("%s", help2->name);
            fscanf(f, "%4s", help2->Mer_modu);
            //printf("%4s\n", help2->Mer_modu);
            getc(f);
            fscanf(f, "%3s", help2->Typ_mer_veliciny);
            //printf("%3s\n", help2->Typ_mer_veliciny);
            fscanf(f, "%lf", &help2->Hodnota);
            //printf("%lf\n", help2->Hodnota);
            fscanf(f, "%d", &help2->Cas);
            //printf("%d\n", help2->Cas);
            fscanf(f, "%li", &help2->Datum);
            help2->next = NULL;
            help3->next = help2;
            help3 = help3->next;
        }
        help = help->next;
        return help;
    }

}

void v(Zaznam** head) {
    Zaznam* help = *head;
    int i = 0;
    while (help != NULL) {
        ++i;
        printf("%d\n", i);
        printf("%lli\n", help->ID_cislo_mer_osoby);
        printf("%s", help->name);
        printf("%3s\n", help->Mer_modu);
        printf("%2s\n", help->Typ_mer_veliciny);
        printf("%lf\n", help->Hodnota);
        printf("%d\n", help->Cas);
        printf("%li\n", help->Datum);
        printf("\n\n");
        help = help->next;
    }
}
void z(Zaznam** head) {
    Zaznam* help = *head;
    long long read;
    scanf("%lli", &read);
    while (help->next != NULL) {
        if (help->next->ID_cislo_mer_osoby == read) {
            help->next = help->next->next;
        }
        else {
            help = help->next;
        }
    }
    Zaznam* help2 = *head;
    if (help2->ID_cislo_mer_osoby == read) {

        help2->ID_cislo_mer_osoby = help2->next->ID_cislo_mer_osoby;
        strcpy(help2->name, help2->next->name);
        help2->Hodnota = help2->next->Hodnota;
        help2->Cas = help2->next->Cas;
        help2->Datum = help2->next->Datum;
        strcpy(help2->Mer_modu, help2->next->Mer_modu);
        strcpy(help2->Typ_mer_veliciny, help2->next->Typ_mer_veliciny);
        help2->next = help2->next->next;
    }

}
void u(Zaznam** head) {
    Zaznam* helpI = *head;
    Zaznam* helpJ;

    Zaznam* temp;
    temp = malloc(sizeof(Zaznam));
    int i = 0, j = 0;
    helpJ = *head;
    // printf("\n%li  %li", helpI->next->Datum, helpI->Datum);
    while (helpI->next->next != NULL) {

        helpJ = *head;
        // Zaznam* temp;
        temp = malloc(sizeof(Zaznam));
        // printf("%d: ",i);
        while (helpJ->next != NULL) {
            //  printf(" %3d",i);
            ++i;
            if ((helpJ->Datum > helpJ->next->Datum) || (helpJ->Datum == helpJ->next->Datum && helpJ->Cas > helpJ->next->Cas)) {
                //   printf("\n%li  %li",helpI->next->Datum, helpI->Datum);
                temp->ID_cislo_mer_osoby = helpJ->ID_cislo_mer_osoby;
                strcpy(temp->name, helpJ->name);
                strcpy(temp->Mer_modu, helpJ->Mer_modu);
                strcpy(temp->Typ_mer_veliciny, helpJ->Typ_mer_veliciny);
                temp->Hodnota = helpJ->Hodnota;
                temp->Cas = helpJ->Cas;
                temp->Datum = helpJ->Datum;

                helpJ->ID_cislo_mer_osoby = helpJ->next->ID_cislo_mer_osoby;
                strcpy(helpJ->name, helpJ->next->name);
                helpJ->Hodnota = helpJ->next->Hodnota;
                helpJ->Cas = helpJ->next->Cas;
                helpJ->Datum = helpJ->next->Datum;
                strcpy(helpJ->Mer_modu, helpJ->next->Mer_modu);
                strcpy(helpJ->Typ_mer_veliciny, helpJ->next->Typ_mer_veliciny);

                helpJ->next->ID_cislo_mer_osoby = temp->ID_cislo_mer_osoby;
                strcpy(helpJ->next->name, temp->name);
                helpJ->next->Hodnota = temp->Hodnota;
                helpJ->next->Cas = temp->Cas;
                helpJ->next->Datum = temp->Datum;
                strcpy(helpJ->next->Mer_modu, temp->Mer_modu);
                strcpy(helpJ->next->Typ_mer_veliciny, temp->Typ_mer_veliciny);
            }
            helpJ = helpJ->next;
        }

        helpI = helpI->next;
        i = 0;
        ++j;
        // printf("\n");
    }

    printf("Spajany zoznam bol usporiadany.\n");
}


void p(Zaznam** head) {
    Zaznam* help = *head;
    Zaznam* counthelp = *head;
    int count = 0;
    while (counthelp != NULL) {
        ++count;
        counthelp = counthelp->next;
    }
    int i = 1, read_ID;
    Zaznam* help2 = malloc(sizeof(Zaznam) * (count + 1));
    scanf("%d", &read_ID);
    printf("input node:\n");
    scanf("%lli", &help2->ID_cislo_mer_osoby);
    getchar();
    gets(help2->name);
    int size = strlen(help2->name);
    help2->name[size++] = '\n';
    help2->name[size] = '\0';
    gets(help2->Mer_modu);
    gets(help2->Typ_mer_veliciny);
    scanf("%lf", &help2->Hodnota);
    scanf("%d", &help2->Cas);
    scanf("%li", &help2->Datum);
    if (read_ID == 1) {
        help2->next = help->next;
        help->next = help2;

        Zaznam* temp = malloc(sizeof(Zaznam));
        temp->ID_cislo_mer_osoby = help->ID_cislo_mer_osoby;
        strcpy(temp->name, help->name);
        strcpy(temp->Mer_modu, help->Mer_modu);
        strcpy(temp->Typ_mer_veliciny, help->Typ_mer_veliciny);
        temp->Hodnota = help->Hodnota;
        temp->Cas = help->Cas;
        temp->Datum = help->Datum;

        help->ID_cislo_mer_osoby = help2->ID_cislo_mer_osoby;
        strcpy(help->name, help2->name);
        help->Hodnota = help2->Hodnota;
        help->Cas = help2->Cas;
        help->Datum = help2->Datum;
        strcpy(help->Mer_modu, help2->Mer_modu);
        strcpy(help->Typ_mer_veliciny, help2->Typ_mer_veliciny);

        help2->ID_cislo_mer_osoby = temp->ID_cislo_mer_osoby;
        strcpy(help2->name, temp->name);
        help2->Hodnota = temp->Hodnota;
        help2->Cas = temp->Cas;
        help2->Datum = temp->Datum;
        strcpy(help2->Mer_modu, temp->Mer_modu);
        strcpy(help2->Typ_mer_veliciny, temp->Typ_mer_veliciny);

    }
    else {
        while (help != NULL) {
            if (i == read_ID - 1) {
                help2->next = NULL;
                help2->next = help->next;
                help->next = help2;
                break;
            }
            ++i;
            help = help->next;
        }
    }
}
void h(Zaznam** head) {
    Zaznam* help = *head;
    char Mer[4];
    scanf("%s", Mer);
    int count = 0;
    while (help != NULL) {
        if (strcmp(Mer, help->Mer_modu) == 0) {
            printf("%d\n", count + 1);
            printf("%lli\n", help->ID_cislo_mer_osoby);
            printf("%s", help->name);
            printf("%3s\n", help->Mer_modu);
            printf("%2s\n", help->Typ_mer_veliciny);
            printf("%lf\n", help->Hodnota);
            printf("%d\n", help->Cas);
            printf("%li\n", help->Datum);
            printf("\n\n");
            ++count;
        }
        help = help->next;
    }
    if (count == 0) {
        printf("Pre meraci modul %s niesu zaznamy.\n", Mer);
    }
}
void r(Zaznam** head) {
    Zaznam* help = *head;
    Zaznam* help2 = *head;
    int c1, c2, tempi;
    scanf("%d %d", &c1, &c2);
    if (c1 > c2) {
        tempi = c1;
        c1 = c2;
        c2 = tempi;
    }
    int i = 1;
    while (help2 != NULL) {
        if (i < c1) {
            help = help->next;
            help2 = help2->next;
        }
        else if (i < c2) {
            help2 = help2->next;
        }
        else {
            Zaznam* temp = malloc(sizeof(Zaznam));
            temp->ID_cislo_mer_osoby = help->ID_cislo_mer_osoby;
            strcpy(temp->name, help->name);
            strcpy(temp->Mer_modu, help->Mer_modu);
            strcpy(temp->Typ_mer_veliciny, help->Typ_mer_veliciny);
            temp->Hodnota = help->Hodnota;
            temp->Cas = help->Cas;
            temp->Datum = help->Datum;

            help->ID_cislo_mer_osoby = help2->ID_cislo_mer_osoby;
            strcpy(help->name, help2->name);
            help->Hodnota = help2->Hodnota;
            help->Cas = help2->Cas;
            help->Datum = help2->Datum;
            strcpy(help->Mer_modu, help2->Mer_modu);
            strcpy(help->Typ_mer_veliciny, help2->Typ_mer_veliciny);

            help2->ID_cislo_mer_osoby = temp->ID_cislo_mer_osoby;
            strcpy(help2->name, temp->name);
            help2->Hodnota = temp->Hodnota;
            help2->Cas = temp->Cas;
            help2->Datum = temp->Datum;
            strcpy(help2->Mer_modu, temp->Mer_modu);
            strcpy(help2->Typ_mer_veliciny, temp->Typ_mer_veliciny);
            break;
        }
        ++i;
    }
}
int main() {
    Zaznam* head = NULL;
    char b;
    while (1) {
        scanf("%c", &b);
        switch (b) {
        case 'n': {
            head = n(&head);
            break;
        }
        case 'v': {
            v(&head);
            break;
        }
        case 'z': {
            z(&head);
            break;
        }
        case 'u': {
            u(&head);
            break;
        }
        case 'p': {
            p(&head);
            break;
        }
        case 'h': {
            h(&head);
            break;
        }
        case 'r': {
            r(&head);
            break;
        }
        case 'k': {
            Zaznam* help;
            while (head != NULL) {
                help = head->next;
                head = NULL;
                head = help;
            }
            return 0;
        }
        }
    }
    return 0;
}
