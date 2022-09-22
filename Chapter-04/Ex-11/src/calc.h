#ifndef CALC_H_INCLUDED
#define CALC_H_INCLUDED

#include <stdbool.h>

#define NUMBER	'0'	/* signal that a number was found */
#define ID	'I'	/* signal that a letter was found */

enum boolean { FALSE , TRUE };	/* f = 0, t = 1 */

extern int variables[];

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

void peek(void);
void duptop(void);
void swap(void);
void clear_stack(void);

void access_to_math_libf(const char []);
int match_libf(const char []);

_Bool handling_vars(int);

#endif	/* CALC_H_INCLUDED */
