#include <bits/stdc++.h>
//根据例子掌握三角形面积的计算
using namespace std;
#define N 50
struct point{
    char rgb;
    int x;
    int y;
    int z;
};
double count_triangle_area(point a,point b,point c,double preArea){
    double area =-1;
    double side[3];//存储三条边的长度;
    side[0] = sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2)+pow(a.z-b.z,2));
    side[1] = sqrt(pow(a.x-c.x,2)+pow(a.y-c.y,2)+pow(a.z-c.z,2));
    side[2] = sqrt(pow(c.x-b.x,2)+pow(c.y-b.y,2)+pow(c.z-b.z,2));
    if(side[0]+side[1]<=side[2] || side[0]+side[2]<=side[1] || side[1]+side[2]<=side[0])
        area = preArea;
    else{
         double p =(side[0]+side[1]+side[2])/2;
         area =sqrt(p*(p-side[0])*(p-side[1])*(p-side[2]));
    }

    return area;
}
int main(){
    int n;
    cin>>n;
    point Allpoint[N];
    for(int i=0;i<n;i++)
        cin>>Allpoint[i].rgb>>Allpoint[i].x>>Allpoint[i].y>>Allpoint[i].z;
    double result = -1;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
           for(int k=j;k<n;k++){
               if(Allpoint[i].rgb == Allpoint[j].rgb&&Allpoint[i].rgb==Allpoint[k].rgb&&Allpoint[j].rgb==Allpoint[k].rgb){
                   if(result<count_triangle_area(Allpoint[i],Allpoint[j],Allpoint[k],result))
                       result = count_triangle_area(Allpoint[i],Allpoint[j],Allpoint[k],result);
               }//1if
               if(Allpoint[i].rgb != Allpoint[j].rgb&&Allpoint[i].rgb!=Allpoint[k].rgb&&Allpoint[j].rgb!=Allpoint[k].rgb){
                   if(result<count_triangle_area(Allpoint[i],Allpoint[j],Allpoint[k],result))
                       result = count_triangle_area(Allpoint[i],Allpoint[j],Allpoint[k],result);
               }//2if
           }
        }//2for
    }//1for

    //count the area
    cout<<fixed<<setprecision(5)<<result<<endl;
    return 0;
}
