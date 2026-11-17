#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

// Ôóíęöč˙ âű÷čńëĺíč˙ ďëîůŕäč ňđĺóăîëüíčęŕ
float area_triangle(int a) {
    return (float)(a * a) / 2;
}

// Ôóíęöč˙ đčńîâŕíč˙ ďĺđĺâĺđíóňîăî ďđ˙ěîóăîëüíîăî ňđĺóăîëüíčęŕ
void draw_triangle(int a, char symbol) {
    printf("\n");

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            if (i == 0 || j == 0 || j == a - i - 1) {
                printf("%c ", symbol);
            }
            else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

// Ôóíęöč˙ ââîäŕ đŕçěĺđŕ ňđĺóăîëüíčęŕ
int get_side() {
    int a;

    do {
        printf("Ââĺäčňĺ äëčíó ńňîđîíű ňđĺóăîëüíčęŕ: ");
        scanf("%d", &a);

        if (a <= 0) {
            printf("Đŕçěĺđ äîëćĺí áűňü ďîëîćčňĺëüíűě.\n");
        }
    } while (a <= 0);

    return a;
}

// Ôóíęöč˙ ńđŕâíĺíč˙ äâóő ňđĺóăîëüíčęîâ ďî ďëîůŕäč
int compare_triangle(int a, int b) {
    if (area_triangle(a) > area_triangle(b))
        return 1;
    else if (area_triangle(a) < area_triangle(b))
        return -1;
    else
        return 0;
}

int main() {
    setlocale(LC_ALL, "RUS");

    int a, choice;
    char symbol;

    printf("Ďđîăđŕěěŕ đŕáîňű ń ňđĺóăîëüíčęîě\n");

    a = get_side();

    do {
        printf("\n===== ĚĹÍŢ =====\n");
        printf("1. Đŕńń÷čňŕňü ďëîůŕäü\n");
        printf("2. Âűâĺńňč îďđĺäĺëĺíčĺ ôčăóđű\n");
        printf("3. Íŕđčńîâŕňü ôčăóđó\n");
        printf("0. Âűőîä\n");
        printf("Âűáĺđčňĺ îďĺđŕöčţ: ");

        scanf("%d", &choice);

        switch (choice) {

        case 1:
            printf("Ďëîůŕäü ňđĺóăîëüíčęŕ: %.2f\n",
                area_triangle(a));
            break;

        case 2:
            printf("\nĎđ˙ěîóăîëüíűé đŕâíîáĺäđĺííűé ňđĺóăîëüíčę — ");
            printf("ýňî ôčăóđŕ, ó ęîňîđîé îäčí óăîë đŕâĺí 90 ăđŕäóńîâ, ");
            printf("ŕ äâĺ ńňîđîíű, îáđŕçóţůčĺ ýňîň óăîë, đŕâíű.\n");
            printf("Ďëîůŕäü âű÷čńë˙ĺňń˙ ďî ôîđěóëĺ S = a * a / 2.\n");
            break;

        case 3:
            printf("Ââĺäčňĺ ńčěâîë äë˙ đčńîâŕíč˙: ");
            scanf(" %c", &symbol, 1);

            draw_triangle(a, symbol);
            break;

        case 0:
            printf("Ďđîăđŕěěŕ çŕâĺđřĺíŕ.\n");
            break;

        default:
            printf("Íĺâĺđíűé ďóíęň ěĺíţ! Ďîâňîđčňĺ ââîä.\n");
        }

    } while (choice != 0);

    return 0;
}
