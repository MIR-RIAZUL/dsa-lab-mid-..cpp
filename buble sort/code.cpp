 #include<iostream>

 using namespace std;

 void bubbleSoert(int arr[],int n)
 {
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
          if(arr[j] >arr[j+1] )
          {
            swap(arr[j],arr[j+1]);
          }
        }
    }
 }

 int main()
 {
    int n;
    cout<<"enter how many number in the array will be :"<<endl;
    cin>>n;
    int arr[n];
    cout<<"enter the array:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    bubbleSoert(arr,n);
    cout<<"after the buble sort:"<<endl;

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }

 }