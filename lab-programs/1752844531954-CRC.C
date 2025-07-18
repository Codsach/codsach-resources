#include <stdio.h>
#include <conio.h>
#include <string.h>

int i,j;

int crc(char *ip, char *op, char *poly, int mode)
{
strcpy(op, ip);
if (mode) {
for ( i = 1; i < strlen(poly); i++)
strcat(op, "0");
}

/* Perform XOR on the msg with the selected polynomial */
for (i = 0; i < strlen(ip); i++) {
if (op[i] == '1') {
for (j = 0; j < strlen(poly); j++) {
if (op[i + j] == poly[j])
op[i + j] = '0';
else
op[i + j] = '1';
}
}
}

/* check for errors. return 0 if error detected */
for (i = 0; i < strlen(op); i++)
if (op[i] == '1')
return 0;

return 1;
}

int main()
{
char ip[50], op[50], recv[50];
char poly[] = "10001000000100001";

printf("Enter the input message in binary: ");
scanf("%s",ip);
crc(ip, op, poly, 1);
printf("The transmitted message is: %s%s \n", ip, op + strlen(ip));
printf("Enter the received message in binary: ");
scanf("%s",recv);

if (crc(recv, op, poly, 0))
printf("No error in data \n");
else
printf("Error in data transmission has occurred \n");
     getch();
return 0;
}