#include <iostream>
#include <cstdlib>
#include <pthread.h>

using namespace std;

#define NUM_THREADS  3

void *PrintSentence(void *threadid)
{
    int tid;
    tid = *(int *)threadid;
    cout<<"Je suis le TRAITEMENT "<<tid<<endl<<"Je suis actif...\n" ;
    pthread_exit(NULL);
}

int main ()
{
  pthread_t threads[NUM_THREADS];
  int rc;
  char TT;

  int MyThreadID=1;

// CREAT THE THREAD HERE
    for (int t = 0; t < NUM_THREADS; t++) {
        rc = pthread_create(&threads[t], NULL, PrintSentence, &t);
        pthread_join(threads[t], NULL);
        if (rc) {
            cout<< "Error:unable to create thread," <<rc<<endl;
            exit(-1);
            exit(EXIT_FAILURE);
        }
    }


    /*
    pthread_exit(NULL);
    rc=pthread_create(&TH1, NULL, PrintSentence, NULL);
    pthread_join (TH1, NULL);

	cout<<"The thread ID is: "<< MyThreadID<<endl;
	++MyThreadID;
	rc=pthread_create(&TH2, NULL, PrintSentence, NULL);
    pthread_join (TH2, NULL);

	cout<<"The thread ID is: "<< MyThreadID<<endl;

*/

      if (rc){
         cout << "Error:unable to create thread," << rc << endl;
         exit(-1);
      }

      cout<<"\nProgram END "<<endl<<"write a letter to end your program\n";
      // pthread_exit(NULL);
   	cin>>TT;
   pthread_exit(NULL);

}
