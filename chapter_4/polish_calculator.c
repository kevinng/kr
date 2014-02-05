#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <math.h>

#define	MAXOP	100 /* max size of operand or operator */
#define	NUMBER	'0' /* signal that a number was found */
#define	SIN	'1' /* signal that a sin operator was found */
#define	COS '2' /* signal that a cos operator was found */
#define	TAN '3' /* signal that a tan operator was found */
#define	SET_VARIABLE '4' /* signal to set a variable */
#define	GET_VARIABLE '5' /* signal to get a variable */
#define RECENT '6' /* signal to get the most recently printed variable */

int getop(char []);
void push(double);
double pop(void);
void clear(void);

/* reverse polish calculator */
int main(int argc, char const *argv[])
{
	int type;
	double op1, op2;
	char s[MAXOP];
	double var_list[26]; /* for 26 letters */
	double last_print= '\0';
	
	while ((type = getop(s)) != EOF)
	{
		switch (type)
		{
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0)
					push(pop() / op2);
				else
					printf("error: zero divisor\n");
				break;
			case '%':
				op2 = pop();
				if (op2 != 0.0)
					push((int)pop() % (int)op2);
				break;
			case '~': /* swap the top 2 elements */
				op2 = pop();
				op1 = pop();
				push(op2);
				push(op1);
				break;
			case '&': /* duplicate the top element */
				op2 = pop();
				push(op2);
				push(op2);
				break;
			case '#': /* show the top element without popping it. */
				op2 = pop();
				last_print = op2;
				printf("\t%.8g\n", op2);
				push(op2);
				break;
			case '!': /* clear the stack */
				clear();
				break;
			case SIN:
				push(sin(pop()));
				break;
			case COS:
				push(cos(pop()));
				break;
			case TAN:
				push(tan(pop()));
				break;
			case RECENT:
				push(last_print);
				break;
			case SET_VARIABLE:
				op1 = pop(); /* variable value */
				var_list[(int)(s[0] - 'a')] = op1;
				push(op1); /* push the variable back so the next operator (usually /n) can work on it */
				break;
			case GET_VARIABLE:
				push(var_list[(int)(s[0] - 'a')]);
				break;
			case '\n':
				last_print = pop();
				printf("\t%.8g\n", last_print);
				break;
			default:
				printf("error: unknown command %s\n", s);
				break;
		}
	}
	return 0;
}

#define	MAXVAL	100 /* maximum depth of value stack */

int sp = 0;
double val[MAXVAL];

void clear()
{
	sp = 0;
}

/* push: push f onto value stack */
void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else
	{
		printf("error: stack empty\n");
		return 0.0;
	}
}

#include <ctype.h>

int getch(void);
void ungetch(int);
void ungets(char[]);

/* getop: get next operator or numeric operand */
int getop(char s[])
{
	int i, c, d, e;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	
	i = 0;
	if (!isdigit(c) && c != '.')
	{
		/* deal with signed numbers */
		if (c == '+' || c == '-')
		{
			if (!isdigit(c = getch()))
			{
				ungetch(c);
				return s[i]; /* return the + or - symbol */
			}

			s[++i] = c;
		}
		else if (c == '=' && isalpha(d = getch()))
		{
			s[0] = d;
			return SET_VARIABLE;
		}
		else if (c == '$' && isalpha(d = getch()))
		{
			s[0] = d;
			return GET_VARIABLE;
		}
		else if (c == '$' && d == '*')
		{
			return RECENT;
		}
		else if (isalpha(c))
		{
			if (c == 's' && (d = getch()) == 'i' && (e = getch()) == 'n') /* sin */
				return SIN;
			else if (c == 'c' && (d = getch()) == 'o' && (e = getch()) == 's') /* cos */
				return COS;
			else if (c == 't' && (d = getch()) == 'a' && (e = getch()) == 'n') /* tan */
				return TAN;

			/* not sure what this is - let main handle it */
			ungetch(d);
			ungetch(e);
			return c;
		}
		else
			return c;
	}

	if (isdigit(c))
	{
		while (isdigit(s[++i] = c = getch()))
			;
	}

	if (c == '.') /* collect fraction part */
	{
		while (isdigit(s[++i] = c = getch()))
			;
	}

	s[i] = '\0';
	if (c != EOF)
		ungetch(c);

	return NUMBER;
}

#define	BUFSIZE	100

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0;

int getch(void) /* get a (possibly pushed back) character */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push a character back on input */
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

void ungets(char s[])
{
	int i;
	for (i = 0; s[i] != '\0'; i++)
		ungetch(s[i]);}
}
































