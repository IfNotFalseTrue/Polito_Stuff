#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_S 18 + 1
#define TRUE 1
#define FALSE 0
#define SEPARATOR ':'
#define PRINT_FORMAT "_minuti"

static void remove_new_line(char *s)
{
    char *p = strchr(s, '\n');
    if(p != NULL) {
        *p = '\0';
    }
}

static void input_string(char *s, int max_len)
{
    fgets(s, max_len, stdin);
    remove_new_line(s);
}

static char parse_string(const char *s, char sep)
{
    size_t i = 0;
    char correct = TRUE;

    for(i = 0; s[i] != '\0' && correct; ++i) {
        if(i == 2) {
            if(s[i] != sep) {
                correct = FALSE;
            }
        }
        else {
            if(!isdigit(s[i])) {
                correct = FALSE;
            }
        }
    }

    return correct;
}


static char validate_time
(const int hours_s1, const int min_s1, const int hours_s2, const int min_s2)
{
    if((hours_s1 >= 0 && hours_s1 < 24) && (min_s1 >= 0 && min_s1 < 60) &&
       (hours_s2 >= 0 && hours_s2 < 24) && (min_s2 >= 0 && min_s2 < 60)) {
          return TRUE;
    } 
    else {
        return FALSE;
    }
}

int main(void)
{
    char s1[MAX_S];
    char s2[MAX_S];
    char string_time_diff[MAX_S];
    int diff_tot_time;
    int hours_s1, min_s1, tot_time_s1;
    int hours_s2, min_s2, tot_time_s2;
    char sep;

    input_string(s1, MAX_S);
    input_string(s2, MAX_S);

    if(parse_string(s1, SEPARATOR) && parse_string(s2, SEPARATOR)) {
        sscanf(s1, "%d %c %d", &hours_s1, &sep, &min_s1);
        sscanf(s2, "%d %c %d", &hours_s2, &sep, &min_s2);
        if(validate_time(hours_s1, min_s1, hours_s2, min_s2)) {
            tot_time_s1 = min_s1 + (hours_s1 * 60);
            tot_time_s2 = min_s2 + (hours_s2 * 60);
            if(tot_time_s1 > tot_time_s2) {
                puts("Il primo orario e' precedente al secondo");
            }
            else {
                diff_tot_time = tot_time_s2 - tot_time_s1;
                sprintf(string_time_diff, "%d%s", diff_tot_time, PRINT_FORMAT);
                puts(string_time_diff);
            }
        }
    }
    else {
        puts("Bad format...");
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}
