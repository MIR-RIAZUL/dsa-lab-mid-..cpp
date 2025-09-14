 #include<iostream>

 using namespace std;

 void selection(int arr[],int n)
 {
    for(int i=0;i<n-1;i++)
    {
        int smallestIndx=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[smallestIndx])
            {
                smallestIndx=j;
            }
        }
        swap(arr[i],arr[smallestIndx]);
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

    selection(arr,n);
    cout<<"after the selectio sort:"<<endl;

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }

 }