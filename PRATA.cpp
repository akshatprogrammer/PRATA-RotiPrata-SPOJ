#include<iostream>
using namespace std;
int roti_paratha(int arr[],int n,int par,int mid){
    int time=0,paratha=0;
    for(int i=0;i<n;i++){
        int j=2;
        time=arr[i];
        while(time<=mid){
            paratha+=1;
            time += arr[i]*j;
            j++;
        }
        if(paratha>=par) return 1;
    }
    return 0;
}
int main(){
    int n,par;
    cin >> par;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];

    int lowerbound=0;
    int upperbound=100000000;    // Paratha <= 1000 and R <= 8  so worst case is pow(10,8)
    int mid,ans;
    while(lowerbound<=upperbound){
        mid = (lowerbound+(upperbound-lowerbound)/2);

        if(roti_paratha(arr,n,par,mid)){
            ans=mid;
            upperbound=mid-1;
        }
        else{
            lowerbound=mid+1;
        }
    }
    cout << ans << endl;

}
