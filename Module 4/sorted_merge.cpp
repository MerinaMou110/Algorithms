// #include<bits/stdc++.h>
// using namespace std;
// void merge(int arr1[],int arr2[],int a,int b){
//     int c=a+b;
// int arr3[c];
// // int i=0,j=0,k=0;
// // while(i<a && j<b){
// //     if(arr1[i]>=arr2[j]){
// //          arr3[k]=arr1[i];
// //          i++;
// //     }
// //     else{
// //         arr3[k]=arr2[j];
// //         j++;
// //     }
// //     k++;
// // }

// // while(i<a){
// //     arr3[k]=arr1[i];
// //     i++;
// //     k++;
// // }
// // while(j<b){
// //     arr3[k]=arr2[j];
// //     j++;
// //     k++;
// // }
// // for(int i=0;i<c;i++){
// //         cout<<arr3[i]<<" ";
// //     }



//     arr1[a-1]=INT_MIN;
//     arr2[b-1]=INT_MIN;
//     int c=a+b;
//     int arr3[c];
//    int ls=0,rs=0;
//     for(int i=0;i<c;i++){
//         if(arr1[ls]>=arr2[rs])
//         {
//             arr3[i]=arr1[ls];
//             ls++;
//         }
//         else{
//             arr3[i]=arr2[rs];
//             rs++;
//         }
//     }
//     for(int i=0;i<a+b;i++){
//         cout<<arr3[i]<<" ";
//     }
// }
// int main()
// {
//     int a,b;
//     cin>>a;
//     int arr1[a];
//     cin>>b;
//     int arr2[b];
//     for(int i=0;i<a;i++){
//         cin>>arr1[i];
//     }
//     for(int i=0;i<b;i++){
//         cin>>arr2[i];
//     }
//     merge(arr1,arr2,a,b);
   
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

void merge(int arr1[], int arr2[], int a, int b, int result[]) {
    int i = 0, j = 0, k = 0;
    
    while (i < a && j < b) {
        if (arr1[i] > arr2[j]) {
            result[k] = arr1[i];
            i++;
        } else {
            result[k] = arr2[j];
            j++;
        }
        k++;
    }

    while (i < a) {
        result[k] = arr1[i];
        i++;
        k++;
    }

    while (j < b) {
        result[k] = arr2[j];
        j++;
        k++;
    }
}

int main() {
    int a, b;
    cin >> a;
    int arr1[a];
    for (int i = 0; i < a; i++) {
        cin >> arr1[i];
    }

    cin >> b;
    int arr2[b];
    for (int i = 0; i < b; i++) {
        cin >> arr2[i];
    }

    int c = a + b;
    int result[c];

    merge(arr1, arr2, a, b, result);

    
    for (int i = 0; i < c; i++) {
        cout << result[i] << " ";
    }
    
    return 0;
}