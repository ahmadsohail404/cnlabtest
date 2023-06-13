#include <stdio.h>

int main() {
    int data[7], datarec[7];
    int c1, c2, c3, c;

    printf("Enter the 4 bits one by one: \n");
    scanf("%d", &data[0]);
    scanf("%d", &data[1]);
    scanf("%d", &data[2]);
    scanf("%d", &data[4]);

    data[6] = data[0] ^ data[2] ^ data[4];
    data[5] = data[0] ^ data[1] ^ data[4];
    data[3] = data[0] ^ data[1] ^ data[2];

    printf("The sent data bits are: \n");
    for (int i = 0; i < 7; i++)
        printf("%d", data[i]);
    printf("\n");

    printf("Enter the received bits: \n");
    for (int i = 0; i < 7; i++)
        scanf("%d", &datarec[i]);

    c1 = datarec[6] ^ datarec[4] ^ datarec[2] ^ datarec[0];
    c2 = datarec[5] ^ datarec[4] ^ datarec[1] ^ datarec[0];
    c3 = datarec[3] ^ datarec[2] ^ datarec[1] ^ datarec[0];
    c = c3 * 4 + c2 * 2 + c1;

    if (c == 0)
        printf("No error\n");
    else {
        printf("Error on bit %d\n", c);

        if (datarec[7 - c] == 0)
            datarec[7 - c] = 1;
        else
            datarec[7 - c] = 0;

        printf("Corrected data: \n");
        for (int i = 0; i < 7; i++)
            printf("%d", datarec[i]);
        printf("\n");
    }
    
    return 0;
}