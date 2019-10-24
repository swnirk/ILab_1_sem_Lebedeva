#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
const char* ENTERTEXT = "/home/ira/CLionProjects/Onegin/Onegin.txt";
const char* RETURNTEXT = "/home/ira/CLionProjects/Onegin/returnonegin.txt";
struct string {

    int sizestring;
    char* ptrs;
};

int SizeTxt (FILE* onegin)

{

    fseek (onegin, 0, SEEK_END);

    int longpoem = ftell(onegin);

    fseek (onegin, 0, SEEK_SET);

    return longpoem;

}

int CounterLine(char *text, int size){
    //printf ("1|%d|", size);
    assert(text);
    //printf ("2|%d|", size);
    int Lines = 0;
    for (int letter = 0; letter < size; letter++)
    {
        if (text[letter] == '\n')
        {
            if (text[letter + 1] == '\n')
                text[letter + 1] =' ';
            Lines++;
            text[letter] == '\0';
        }
    }

    return Lines;
}

void CreateStrPtrs (char* maspoem, int longpoem, struct string* masptrsstring) {

    assert (maspoem != NULL);
    assert (longpoem != NULL);

    int i = 0;
    int j = 0;
    int flag = 1;
    masptrsstring[0].ptrs = maspoem;
    for (i = 0; i < longpoem; i++) {

        if (maspoem[i] == '\n') {

            masptrsstring[flag].ptrs = maspoem + i + 1;
            masptrsstring[flag - 1].sizestring = i - j;
            j = i;
            flag++;
            maspoem[i] = '\0';
        }
    }
}

int compare (const void * arg1, const void * arg2) {

    assert(arg1);
    assert(arg2);

    struct string a = *(struct string*) arg1;
    struct string b = *(struct string*) arg2;

    int j = 0;
    int k = 0;
    int res = 0;

    char* ptrs1 = a.ptrs;
    char* ptrs2 = b.ptrs;

    while (*ptrs1 == *ptrs2 && *(ptrs1 + j) && *(ptrs2 + k)) {

        while (isalpha (*(ptrs1 + j)) == 0) {
            j++;
        }

        while (isalpha (*(ptrs2 + k)) == 0) {
            k++;
        }

        res = *(ptrs1 + j) - *(ptrs2 + k);
        if (res == 0) {
            j++;
            k++;
        }

    }
    return res;
}



int main () {

    FILE * onegin = fopen (ENTERTEXT,"r");

    assert( onegin );

    int longpoem = SizeTxt(onegin);

    printf ("size is %d", longpoem);

    char* maspoem = (char*)calloc (longpoem + 1, sizeof (char));

    int num = fread (maspoem, sizeof (char), longpoem, onegin);

    for(int i = 0; i < longpoem; i++) {

        printf ("%c", maspoem[i]);

  }

   // int numlines = 137;

   int  numlines = CounterLine (maspoem, longpoem);

    printf ("numlines is %d|", numlines);

    struct string* masptrsstring = (struct string*)calloc (numlines + 1, sizeof (struct string)+1);

    CreateStrPtrs(maspoem, longpoem, masptrsstring);

    qsort (masptrsstring, numlines, sizeof (struct string), compare);

    FILE * returnonegin = fopen (RETURNTEXT, "w");

    for (int q = 0; q < numlines; q++)
        printf("%s\n", masptrsstring[q].ptrs);

    fclose (returnonegin);

    fclose (onegin);

    return 0;
}


