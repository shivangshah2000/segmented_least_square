#include <bits/stdc++.h>

using namespace std;

#define INF numeric_limits<double>::infinity()

int main(){
    int N,C, i,j,interval_len,x,y ,k;
    cout<<"Enter N: ";
    cin>>N;
    cout<<"Enter "<<N << " points\n";
    vector < pair<int,int> > points ;
    points.push_back({INT_MIN,INT_MIN});   // adding dummy value so that indexing starts with 1
    for(i=1;i<=N;i++){
        cin>>x>>y;
        points.push_back({x,y});
    }
    cout<<"Enter C: ";
    cin>>C;

    // sorting the points on basis of x axis
    sort(points.begin(),points.end());
    for(i=1;i<=N;i++){
        cout<<points[i].first<<" "<<points[i].second<<endl;
    }
    int slope[N+1][N+1] , intercept[N+1][N+1] , E[N+1][N+1] = {0};
    int cumx[N+1], cumy[N+1] , cumxy[N+1], cumxsqr[N+1];        // cummulative arrays to store summation value
    cumx[0] = 0;
    cumy[0] = 0;
    cumxy[0] = 0;
    cumxsqr[0] = 0;
    
    // finding error values for each segment
    int x_seg_sum , y_seg_sum , xy_seg_sum , xsqr_seg_sum; 
    for(j=1;j<=N;j++){
        cumx[j] = cumx[j-1] + points[j].first;
		cumy[j] = cumy[j-1] + points[j].second;
		cumxy[j] = cumxy[j-1] + points[j].first * points[j].second;
		cumxsqr[j] = cumxsqr[j-1] + points[j].first* points[j].first;
        for(i=1;i<=j;i++){
            x_seg_sum = cumx[j] - cumx[i-1];
            y_seg_sum = cumy[j] - cumy[i-1];
            xy_seg_sum = cumxy[j] - cumxy[i-1];
            xsqr_seg_sum = cumxsqr[j] - cumxsqr[i-1];
            interval_len = j- i +1 ;
            int denominator = interval_len*xsqr_seg_sum - x_seg_sum*x_seg_sum;
            if(denominator == 0){
                slope[i][j] = INF;            // infinity value
            }
            else{
                    slope[i][j] = (interval_len*xy_seg_sum - x_seg_sum*y_seg_sum) / (double(denominator));
            }
            intercept[i][j] = ( y_seg_sum - slope[i][j]*x_seg_sum ) / double(interval_len) ;
            for(k=i;k<=j;k++){
                int error = points[k].second - ( slope[i][j] *points[k].first + intercept[i][j] ) ;        //  y - yi  where yi = ax +b
                E[i][j] += pow(error,2);
            }
        }
    }

   
}
