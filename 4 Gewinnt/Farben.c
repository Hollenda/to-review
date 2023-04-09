#include <stdio.h>
#include <stdlib.h>


void initialize_color(void)
{
    system("COLOR 0f");
}
void reset_color(void)
{
    printf("\033[0m");
}
void red(void)
{
    printf("\033[0;31m");
}
void green(void)
{
    printf("\033[0;32m");
}
void yellow(void)
{
    printf("\033[0;33m");
}
void blue(void)
{
    printf("\033[0;34m");
}
void purple(void)
{
    printf("\033[0;35m");
}
void cyan(void)
{
    printf("\033[0;36m");
}
void white(void)
{
    printf("\033[0;37m");
}
