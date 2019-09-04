#define NUMBER '0'
#define FUNC 'f'
#define ERR  'e'

int getop(char []);

int getch(void);
void ungetch(int);

void push(double);
void swap(void);
void dup(void);
void clear(void);
double look(void);
double pop(void);

void mathf(char s[]);
