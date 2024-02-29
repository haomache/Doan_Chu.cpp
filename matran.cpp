#include <iostream>
#include <fstream>
using namespace std;
int main(){
    ifstream file("matran.dat");
    int dong;
    file>>dong;
    int cot;
    file>>cot;
    int a[dong][cot];
    cout<<dong<<" "<<cot<<endl;
    int sum=0;
    int tongdong[5];
    for(int i=0; i<dong; i++){
        for(int j =0; j<cot ;j++){
            file>>a[i][j];
        }
    }
     for(int i=0; i<dong; i++){
        for(int j =0; j<cot ;j++){
            cout<<a[i][j]<<" ";
            sum+=a[i][j];
            tongdong[i]=sum;
            
        }
        cout<<endl;
        sum=0;
     }

     //phan 2:
    for(int i=0; i<dong ;i++){
        cout<<"Row "<<i+1<<": "<<tongdong[i]<<endl;
    }

    //phan 3:
    int tichcot=1;
    for(int i=0; i<cot; i++){
        int tichcot=1;
        for(int j=0; j<dong; j++){
            tichcot*=a[j][i];
        }
        cout<<"Product col "<<i+1<<": "<<tichcot<<endl;
    }
    //phan 4:
    int maxx=a[0][0];
    int minn=a[0][0];
    for(int i=0; i<dong; i++){
        for(int j =0; j<cot ;j++){
            if(a[i][j]>=maxx){
                maxx=a[i][j];
            }
            if(a[i][j]<=minn){
                minn=a[i][j];
            }
        }
    }
    cout<<"Max of matrix: "<<maxx<<endl;
    cout<<"Min of matrix: "<<minn<<endl;
    
    //phan 5:
    int demmax=1;
    int demmin=1;
    for(int i=0; i<dong; i++){
        for(int j=0; j<cot ; j++){
            if(maxx==a[i][j]){
                cout<<"Position max "<<demmax<<": (row "<<i<<","<<"col "<<j<<")"<<endl;
                demmax++;
            }
            if(minn==a[i][j]){
                cout<<"Position min "<<demmin<<": (row "<<i<<","<<"col "<<j<<")"<<endl;
                demmin++;
            }
        }

    }
    file.close();
    return 0;
}