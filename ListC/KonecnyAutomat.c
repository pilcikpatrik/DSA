#include <stdio.h>


typedef enum {START, MOZNA_POZNAMKA, JEDNORADKOVA} tStavy;
int main()
{
    tStavy stav = START;
    printf("Odstranovac poznamek. Zadej vstup\n");
    int znak;
    while((znak = getchar())!=EOF) {
        switch (stav) {
        case START:
            if (znak == '/') {
                stav = MOZNA_POZNAMKA;
            }else {
                putchar(znak);
            }
            break;
        case MOZNA_POZNAMKA:
            if (znak == '/') {
                stav = JEDNORADKOVA;
            }else {
                putchar('/');
                putchar(znak);
            }
            break;
        case JEDNORADKOVA:
            if (znak == '\n') {
                stav = START;
            }else {
                putchar('\n');
            }
            break;
        }
    }
    return 0;
}
