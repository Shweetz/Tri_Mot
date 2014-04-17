#include <stdio.h>

char* ConstruireMot(char mot_provisoire[], int nombreLettres)
{
    char mot[nombreLettres];
    char *p_mot = mot;
    for (int i=0; i<nombreLettres; i++)
    {
        mot[i] = mot_provisoire[i];
    }
    return p_mot;
}

/*void NoterLettre(char mot_provisoire[], int nombreLettres, char lettre_char)
{
    mot_provisoire[nombreLettres] = lettre_char;
}*/

char *LireMot(FILE *monFichier)
{
    if (monFichier == NULL)
        perror ("Error opening file");
    else
    {
        int nombreLettres = 0;
        char lettre_char;

        char mot_provisoire[30];
        //const char *p_mot_provisoire = mot_provisoire;

        fscanf(monFichier, "%c", &lettre_char);

        while ( ! feof (monFichier) )
        {
            if (lettre_char == '.' || lettre_char == ',' || lettre_char == ';'
                                   || lettre_char == '(' || lettre_char == ')')
            {
                //AssemblerMot(p_mot, nombreLettres)
                //ConstruireMot(mot_provisoire, nombreLettres);
                nombreLettres = 0;
                fscanf(monFichier, "%c", &lettre_char);
                printf("%c", '\n');
            }
            if (lettre_char == ' ')
            {
                //AssemblerMot(p_mot, nombreLettres)
                //ConstruireMot(mot_provisoire, nombreLettres);
                nombreLettres = 0;
                printf("%c", ' ');
            }
            else
            {
                //mot_provisoire[nombreLettres] = lettre_char;
                nombreLettres++;
                printf("%c", lettre_char);
            }
            fscanf(monFichier, "%c", &lettre_char);
        }
    }
    return 0;
}

int main()
{
    FILE *monFichier;
    monFichier = fopen ("monFichier.txt" , "r");
    //printf("coucou\n");
    char *mot;

    do
    {
        mot = LireMot (monFichier);
        printf(mot);
        printf("\n");
    }
    while (mot != NULL);

    fclose (monFichier);

}

