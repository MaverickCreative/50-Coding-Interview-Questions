#include<bits/stdc++.h>

using namespace std;

double calculateMedian(int a[], int start, int end)
{
	if((start-end)%2==0)
	{
		return a[start + end/2];
	}
	else
	{
		return 1.0*((a[start +end/2]) + (a[start + end/2 + 1]))/2;	
	}
}

double findMedian(int a[], int b[], int starta, int enda, int startb, int endb)
{
	if((enda- starta) == 0 && (endb-startb) == 0)
	{
		return (a[0]+b[0])/2;
	}
	if((enda-starta) == 1 && (endb-startb) == 1)
	{
		return 1.0*((max(a[0],b[0]) + min(a[1],b[1]))/2);
	}

	double m1 = findMedian(a,starta,enda);
	double m2 = findMedian(b,startb,endb);

	if(m2==m1)
	{
		return m2;
	}

	if(m1<m2)
	{
		 if ((enda - starta) % 2 == 0)  
	            {
	                starta = starta + (enda - starta) / 2;
                endb = startb + (endb - startb) / 2;
	            }
	            else
	            {
	                starta = starta + (enda - starta) / 2;
	                endb = startb + (endb - startb) / 2 + 1;                
	            }
	}

	else  
	        {
	            if ((endIndexB - startIndexB) % 2 == 0)  
	            {
	                startb = startb + (endb - startb) / 2;
	                enda = starta + (enda - starta) / 2;
	            }	           
	             else
	            {	
	            	startb = startb + (endb - startb) / 2;
	                enda = starta + (enda - starta) / 2 + 1; 
            	}    
        }

        return findMedian(a,b,starta,enda,startb,endb);
}

int main()
{
	int a[] = {1,2,3,4,5,6};
	int b[] = {0,0,0,10,10,10};
	double ans = findMedian(a,b,0,5,0,5);
	cout<<ans<<endl;
}