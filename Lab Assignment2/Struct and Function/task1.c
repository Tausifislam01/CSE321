#include <stdio.h>

struct Items{
int quantity;
float unitprice;
};

float calc(struct Items paratha, struct Items vegetable, struct Items water){
float res= 0.0;
res = (paratha.quantity*paratha.unitprice) + (vegetable.quantity*vegetable.unitprice)+ (water.quantity*water.unitprice);
return res;


}

int main(){

struct Items paratha, vegetable, water;
int people;
float bill, individual_bill;

printf("Quantity of paratha: ");
scanf("%d", &paratha.quantity);
printf("Unit Price: ");
scanf("%f", &paratha.unitprice);

printf("Quantity of Vegetable: ");
scanf("%d", &vegetable.quantity);
printf("Unit Price: ");
scanf("%f", &vegetable.unitprice);

printf("Quantity of water: ");
scanf("%d", &water.quantity);
printf("Unit Price: ");
scanf("%f", &water.unitprice);

printf("Number of People: ");
scanf("%d", &people);

bill = calc(paratha, vegetable, water);

individual_bill = bill/people;
printf("Individual people will pay: %.2f tk\n", individual_bill);

return 0;

}
