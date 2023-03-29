#include <iostream>
#include <vector>
#include <string>


using namespace std;
//quick sort sorting algorithm
typedef struct record{
    string Direction;
    int Year;
    string Date;
    string Weekday;
    string Country;
    string Commodity;
    string Transport_Mode;
    string Measure;
    long int Value;
    long int Cumulative;
}Record;



int Partition(vector <Record> &Data, int s, int e)
{

    long int pivot = Data.front().Cumulative;
    int pIndex = e;

    for(int i=e; i>s; i--)
    {
        if(Data.at(i).Cumulative>pivot)
        {

            swap(Data.at(i), Data.at(pIndex));
            pIndex--;
        }
    }


    swap(Data.at(s), Data.at(pIndex));


    return pIndex;

}


void QuickSort(vector <Record> &Data, int s, int e)
{

    if(s<e)
    {
        int p = Partition(Data, s, e);
        QuickSort(Data, s, (p-1)); //recursive QuickSort call for left partition
        QuickSort(Data, (p+1), e); //recursive QuickSort call for right partition

    }

}



int main(){
vector <Record> Data;

Record rec1, rec2, rec3;


rec1.Cumulative = 467657347;
rec2.Cumulative = 405834737;
rec3.Cumulative = 739244729;

Data.push_back(rec1);        //to replace them with iterative method for pushing back to vector the Cumulatives.
Data.push_back(rec2);
Data.push_back(rec3);



cout<<"Before Sorting:"<<endl;
for(int i=0; i<Data.size(); i++)
    {

        cout<<Data.at(i).Cumulative<<" ";

    }
cout<<endl;

QuickSort(Data, 0, (Data.size()-1));

cout<<"After Sorting:"<<endl;
for(int i=0; i<Data.size(); i++)
    {

        cout<<Data.at(i).Cumulative<<" ";

    }




return 0;


}

