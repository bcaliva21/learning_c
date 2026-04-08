#include <stdio.h>

struct car {
	char *name;
	float price;
	int speed;
};

int copying_structs(void)
{
	struct car a, b;

	b = a; // copy the struct
}

int set_name(struct car *c, char *new_name)
{
	c->name = new_name;
}

int set_speed(struct car *c, int new_speed)
{
	c->speed = new_speed;
}

int set_price(struct car *c, float new_price)
{
	// c.price = new_price; // Error.
	// (*c).price = new_price; // non-idiomatic
	c->price = new_price; // That's the bacon!
}

int mutation(void)
{
	struct car saturn;
	saturn.name = "Saturn SL/2";
	saturn.price = 15999.99;
	saturn.speed = 175;

	printf("Name:          %s\n", saturn.name);
	printf("Price:         %f\n", saturn.price);
	printf("Speed:         %d\n", saturn.speed);

	set_name(&saturn, "Saturn SL/3");
	set_speed(&saturn, 999);
	set_price(&saturn, 199);

	printf("Name:          %s\n", saturn.name);
	printf("Price:         %f\n", saturn.price);
	printf("Speed:         %d\n", saturn.speed);
}

int basics(void)
{
	struct car saturn;
	saturn.name = "Saturn SL/2";
	saturn.price = 15999.99;
	saturn.speed = 175;

	printf("Name:          %s\n", saturn.name);
	printf("Price:         %f\n", saturn.price);
	printf("Speed:         %d\n", saturn.speed);

	struct car sbturn = {"Saturn SL/3", 16000.99, 185};
	printf("Name:          %s\n", sbturn.name);
	printf("Price:         %f\n", sbturn.price);
	printf("Speed:         %d\n", sbturn.speed);
}

int main(void)
{
	mutation();
}
