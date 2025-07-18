#include <stdio.h>
#include <conio.h> // Removed for portability

int main() {
    int data[7];
    int data_at_reciever[7];

    int c, c1, c2, c3;
    int i;
    clrscr();

    printf("Enter 4 bits of data one by one:\n");
    scanf("%d", &data[0]);
    scanf("%d", &data[1]);
    scanf("%d", &data[2]);
    scanf("%d", &data[4]);

    // Calculate parity bits
    data[6] = data[0] ^ data[2] ^ data[4];
    data[5] = data[0] ^ data[1] ^ data[4];
    data[3] = data[0] ^ data[1] ^ data[2];

    printf("\nEncoded data is: ");
    for (i = 0; i < 7; i++) {
	printf("%d", data[i]);
    }

    printf("\n\nEnter received data bits one by one:\n");
    for (i = 0; i < 7; i++) {
	scanf("%d", &data_at_reciever[i]);

    }

    // Error checking
    c1 = data_at_reciever[6] ^ data_at_reciever[4] ^ data_at_reciever[2] ^ data_at_reciever[0];
    c2 = data_at_reciever[5] ^ data_at_reciever[4] ^ data_at_reciever[1] ^ data_at_reciever[0];
    c3 = data_at_reciever[3] ^ data_at_reciever[2] ^ data_at_reciever[1] ^ data_at_reciever[0];

    c = c3 * 4 + c2 * 2 + c1;




if(c==0){
printf("No error during transmission\n");
}
else{
printf("error found at position %d",c);

printf("\n data sent:");
for(i=0;i<7;i++){
  printf("%d",data[i]);
}

printf("\n Data recieved:");
for(i=0;i<7;i++){
  printf("%d",data_at_reciever[i]);
}

data_at_reciever[c-1] = data_at_reciever[c-1]^1;
printf("\n Corrected Message is:");
for(i=0;i<7;i++){
  printf("%d",data_at_reciever[i]);
}
}
getch();
return 0;

}