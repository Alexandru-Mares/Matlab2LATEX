#include <iostream>
#include <fstream>
using namespace std;

int main ()
{
  FILE * pFile;
  FILE * out;
  char c;
  int i;
  int n = 0;
  int contor;
  //open input/output files
  pFile=fopen ("in.txt","r");//inpute file, contains matlab code
  out=fopen("out.txt","w");//out file contains matlab code formated to look properly into a latex todument
  if (pFile==NULL) perror ("Error opening file");

  else
  {
      //starts figure
    fprintf(out,"\\begin{figure}[H]\n\\begin{itemize}\n\\setlength{\\itemsep}{0pt}\n\\setlength{\\parskip}{0pt}\n\\setlength{\\parsep}{0pt}\n\\item ");
    do {
      c = getc (pFile);
      contor=0;
      while(c==' ')
        {
            contor++;
            c = getc (pFile);
            if(contor==4)
            {
                fprintf(out,"\\qquad ");
                contor=0;
            }
        }
        for(i=0;i<contor;i++)
        {
            fprintf(out," ");
        }

      if(c=='\t')
        c=c;
        //checks for special characters
      else if (c == '\n')  fprintf(out,"\n\\item ");
      else if (c =='&') fprintf(out,"\\&");
      else if (c== '^') fprintf(out,"\\textasciicircum");
      else if (c== '>') fprintf(out,"$>$");
      else if (c== '<') fprintf(out,"$<$");
      else if (c== EOF)
      break;
      else fprintf(out,"%c",c);
    } while (c != EOF);
    fclose (pFile);

  }
  //ends figure
  fprintf(out,"\n\\end{itemize}\n\\end{figure}");

  return 0;
}

