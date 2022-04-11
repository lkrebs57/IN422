#include<iostream>
#include<math.h>
#define nmax 100
using namespace std;


double max_emp(double T[])
{
    double max_t=0;
    int max_i=0;
    int size_T=sizeof(T)/sizeof(double);
    for(int i=0;i<size_T+1;i++)
    {
       if(T[i]>max_t)
       {
            max_t=T[i];
            max_i=i;
       }

    }
    return max_i;
}
int main()
{   int n;

    cout<<"Give me the number of task(s): ";
    cin>>n;
    double Task[n][5];
    double Task_r[n];
    double Task_r1[n];
    for(int i=0;i<sizeof(Task_r)/sizeof(double);i++)
    {
        Task_r1[i]=Task_r[i];
    }
    double sum=0;
    double result_d=double(n)*(pow(2.0,(1/double(n)))-1);
    int biggest_p=0;
    for(int i=0;i<n;i++)
    {
        cout<<"---------Task n_"<<i+1<<"-----------"<<endl;
        cout<<"Arrival time of task n_"<<i+1<<"= ";
        cin>>Task[i][0];
        cout<<"Capacity of task n_"<<i+1<<"= ";
        cin>>Task[i][1];
        cout<<"Deadline of task n_"<<i+1<<"= ";
        cin>>Task[i][2];
        cout<<"Period of task n_"<<i+1<<"= ";
        cin>>Task[i][3];
        cout<<"Priority of task n_"<<i+1<<"= "<<1/Task[i][3]<<endl;
        Task[i][4]=1/Task[i][3];
        cout<<"----------------------------\n"<<endl;
        sum=sum+Task[i][1]/Task[i][3];
        if (Task[i][2]>biggest_p)
            biggest_p=Task[i][2];
        Task_r[i]=Task[i][4];

    }
    int SCH[biggest_p]={0};


    if (sum<=result_d)
    {   cout <<"Acceptation : "<<sum<<" < "<<result_d<<endl;
        cout <<"We can compute\n"<<endl;
        for (int i=0; i<sizeof(Task_r)/sizeof(double);i++)
        {
            int k=max_emp(Task_r);
            int g=Task[k][1];
            int nb_p=trunc(biggest_p/Task[k][3]);
            //cout <<"k="<<k<<endl;
            for (int j=0;j<biggest_p;j++)
            {
                for (int nbv=0;nbv<nb_p;nbv++)
                {
                    if (j==Task[k][3]*nbv)
                    {
                        for(int i=0;i<sizeof(Task_r)/sizeof(double);i++)
                        {
                            Task_r[i]=Task_r1[i];
                            g=Task[k][1];
                        }

                    }
                }

                if (g!=0 && SCH[j]==0 && Task[i][0]<=j )
                {
                        SCH[j]=k+1;
                        g--;
                }



            }
            Task_r[k]=0.0;

        }
        for (int i = 0; i < biggest_p; i++)
            if(SCH[i]!=0)
            {
                cout <<"Task "<<SCH[i] << " ";
            }
            else
            {
                cout <<"None ";
            }

        cout << endl;
    }
    else
    {   cout <<"Acceptation : "<<sum<<" > "<<result_d<<endl;
        cout<<"The scheduling can't be done"<<endl;
    }
}

