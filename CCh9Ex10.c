/*Create a structure that can describe a restaurant. It should have members that include the name, address, average cost, and type of food. Write a routine that prints out all restaurants of a given type in order of cost, with the least costly first.*/
#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE 7

enum CUISINE {THAI, MEXICAN, CHINESE, JAPAN, TURKISH, MEDITERRANEAN, LEBANESE, ITALIAN, FRENCH, GREEK};
const char* cuisine_array[] = {"THAI", "MEXICAN", "CHINA", "JAPAN", "TURKISH", "MEDITERRANEAN", "LEBANESE", "ITALIAN", "FRENCH", "GREEK"};
typedef enum CUISINE CUISINE;

typedef struct restaurant {
	const char* name;
	const char* address;
	float average_cost;
	CUISINE type_of_food;
}restaurant;

void print_restaurant(restaurant *r) {
	printf("%s\t%s\t%.2f\t%s\n", r->name, cuisine_array[r->type_of_food], r->average_cost, r->address);
}

int compare(const restaurant* r1, const restaurant* r2) {
	return (r1->average_cost > r2->average_cost);
}

int main(void) {
	restaurant restaurants[ARRAY_SIZE];
	int i;
	CUISINE selected_cuisine;
	restaurants[0].name = "Izmir Restaurant";
	restaurants[0].address = "Balcova, Izmir";
	restaurants[0].average_cost = 120.45;
	restaurants[0].type_of_food = TURKISH;
	restaurants[1].name = "Cancun Restaurant";
	restaurants[1].address = "Av. Leona Vicario, Cancun";
	restaurants[1].average_cost = 145.60;
	restaurants[1].type_of_food = MEXICAN;
	restaurants[2].name = "Cannes Restaurant";
	restaurants[2].address = "Rue d'Antibes";
	restaurants[2].average_cost = 945.75;
	restaurants[2].type_of_food = FRENCH;
	restaurants[3].name = "Shangai Restaurant";
	restaurants[3].address = "Guangdong Road";
	restaurants[3].average_cost = 540.00;
	restaurants[3].type_of_food = CHINESE;
	restaurants[4].name = "Livorno Restaurant";
	restaurants[4].address = "La Barrocciaia";			
	restaurants[4].average_cost = 700.90;
	restaurants[4].type_of_food = ITALIAN;
	restaurants[5].name = "Ortaklar Cop Sis";
	restaurants[5].address = "Ortaklar, Aydin";
	restaurants[5].average_cost = 155.09;
	restaurants[5].type_of_food = TURKISH;
	restaurants[6].name = "Veracruz Restaurant";
	restaurants[6].address = "Paso Y Troncoso";
	restaurants[6].average_cost = 210.21;
	restaurants[6].type_of_food = MEXICAN;
	for(i = 0; i < ARRAY_SIZE; ++i)
		print_restaurant(&restaurants[i]);
	printf("Filter by type_of_food: ");
	for(i = 0; i < 10; ++i)
		printf(" %s(%d)", cuisine_array[i], i);
	printf("\n");
	scanf("%d", &selected_cuisine);
	printf("Selected cuisine = %s\n", cuisine_array[selected_cuisine]);
	qsort(restaurants, ARRAY_SIZE, sizeof(restaurant), compare);
	for(i = 0; i < ARRAY_SIZE; ++i)	
		if(restaurants[i].type_of_food == selected_cuisine)
			print_restaurant(&restaurants[i]);
	return 0;
}
