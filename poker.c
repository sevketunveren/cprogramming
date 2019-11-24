#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NDEALS 3000000
#define NPLAYERS 6

typedef enum {clubs, diamonds, hearts, spades} cdhs;

struct card {
	int pips;
	cdhs suit;
};

typedef struct card card;

card assign_values(int pips, cdhs suit);
void prn_card_values(card* c_ptr);
void play_poker(card deck[52]);
void shuffle(card deck[52]);
void swap(card* p, card* q);
void deal_the_cards(card deck[52], card hand[NPLAYERS][5]);
int is_flush(card h[5]);

void main() {
	cdhs suit;
	int i, pips;
	card deck[52];
	for(i=0; i < 52; ++i) {
		pips = i % 13 + 1;
		if(i < 13)
			suit = clubs;
		else if(i < 26)
			suit = diamonds;
		else if(i < 39)
			suit = hearts;
		else
			suit = spades;
		deck[i] = assign_values(pips, suit);
	}
	play_poker(deck);
}

card assign_values(int pips, cdhs suit) {
	card c;
	c.pips = pips;
	c.suit = suit;
	return c;
}

void prn_card_values(card* c_ptr) {
	char* suit_name;
	if(c_ptr->suit == clubs)
		suit_name = "clubs";
	else if(c_ptr->suit == diamonds)
		suit_name = "diamonds";
	else if(c_ptr->suit == hearts)
		suit_name = "hearts";
	else if(c_ptr->suit == spades)
		suit_name = "spades";
	printf("card %2d of %s\n", c_ptr->pips, suit_name);
}

void play_poker(card deck[52]){
	int i = 0, j = 0, h = 0, flush_cnt = 0, hand_cnt = 0;
	card hand[NPLAYERS][5];
	srand(time(NULL));
	for(; i < NDEALS; ++i) {
		shuffle(deck);
		deal_the_cards(deck, hand);
		for(j = 0; j < NPLAYERS; ++j) {
			++hand_cnt;
			if(is_flush(hand[j])) {
				flush_cnt++;
				for(h = 0; h < 5; ++h)
					prn_card_values(&hand[j][h]);
				printf("%s%d\n\%s%d\n%s%f\n", "Hand Number:", hand_cnt, "Flush Number:", flush_cnt, "Flush probability:", (double) flush_cnt/hand_cnt);
			}
		}
	}
}

void deal_the_cards(card deck[52], card hand[NPLAYERS][5]) {
	int card_cnt = 0, i, j = 0;
	for(; j < 5; ++j)
		for(i = 0; i < NPLAYERS; ++i) {
			hand[i][j] = deck[card_cnt++];
		}
}

void shuffle(card deck[52]) {
	int i = 0, j;
	for(; i < 52; ++i) {
		j = rand() % 52;
		swap(&deck[i], &deck[j]);
	}
}

void swap(card* p, card* q) {
	card tmp;
	tmp = *p;
	*p = *q;
	*q = tmp;
}

int is_flush(card h[5]) {
	int i = 1;
	for(; i < 5; ++i)
		if(h[i].suit != h[0].suit)
			return 0;
	return 1;
} 
