#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;


#define NUM_THREADS  3
#define MAX_value 150

void *PrintSentence(void *threadid)
{
    char * value;
    value = (char*)threadid;
    cout<<"La chaine transmise est : "<<value<<endl;


    pthread_exit(NULL);
}

void *Visualisation(void *threadid)
{
    char * value;
    value = (char*)threadid;

    int n = strlen(value);
    char *rev = new char[n+1];
    strcpy(rev, value);
    for (int i=0, j=n-1; i<j; i++,j--)
        swap(rev[i], rev[j]);
    cout<<"La chaine inverse est : "<<rev<<endl;

    pthread_exit(NULL);
}
void *Timer(void *threadtime)
{
    int * value;

    time_t debut;
	time_t fin;
	while(true)
    {
        time(&debut);
        time(&fin);
        while(fin-debut<5)
        {
            time(&fin);
        }
        cout<<endl<<"Give me a text : ";
    }
    pthread_exit(NULL);
}

void *Saisie(void *threadvalue)
{
    pthread_t TH;
    int rc;
    char* TT = (char*)threadvalue;
    cout<<"Give me a text : ";
    rc = pthread_create(&TH, NULL, Timer, NULL);
    if (rc){
        cout << "Error:unable to create thread," << rc << endl;
        exit(-1);
    }

    cin>>TT;
    pthread_cancel(TH);
    pthread_exit(NULL);
}

int main ()
{   pthread_t TH1,TH2,TH3,TH4;
    int rc;

    char * TT=NULL;
    cout<<"================= TP1 EX3/4 ================= : "<<endl;
    rc = pthread_create(&TH1, NULL, Saisie, &TT);
    pthread_join(TH1,NULL);
    if (rc){
        cout << "Error:unable to create thread," << rc << endl;
        exit(-1);
    }

    rc=pthread_create(&TH2, NULL, PrintSentence, &TT);
    pthread_join(TH2,NULL);
    if (rc){
         cout << "Error:unable to create thread," << rc << endl;
         exit(-1);
    }
    rc=pthread_create(&TH3, NULL, Visualisation, &TT);
    pthread_join(TH3,NULL);
    if (rc){
         cout << "Error:unable to create thread," << rc << endl;
         exit(-1);
    }

    cout<<"\nFin du programme \n";

    return 0;

}
