/*#include <stdio.h>
#include <windows.h>

#define PROGRESS_BAR_SIZE 40

void print_n_chars(int n, int c) {
    while (n-- > 0) putchar(c);
}

void display_progress_bar(int p) {
    putchar('\r');
    putchar('[');
    print_n_chars(PROGRESS_BAR_SIZE * p / 100, '|');
    print_n_chars(PROGRESS_BAR_SIZE - PROGRESS_BAR_SIZE * p / 100, ' ');
    putchar(']');
}

int main(void) {
    int p;
    for (p = 0; p <= 100; ++p) {
        display_progress_bar(p);
        Sleep(100);
    }
    return 0;
}
*/

#include <stdio.h>
#include <time.h>

void sleep ( long milli )
{
  clock_t end, current = clock();
  for( end = current + milli; current < end; current = clock() );
}

int main ( void )
{
  int x = 0;
  const char *barRotate = "|\\-/";
  printf ( "Loading configuration files... " );
  for ( ; ; ) {
    if ( x > 3 ) x = 0;
    printf ( "%c\b", barRotate[x+2] );
    sleep ( 20);
  }

  return 0;
}
