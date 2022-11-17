#include <iostream>
int i,j,k,a,b,u,v,n,ne=1;
int min,mincost=0,cost[9][9],parent[9];
int find(int);
int uni(int,int);

int main() {
  	
	std::cout<<"\n\tImplementation of Kruskal's algorithm\n";
	std::cout<<"\nEnter the no. of vertices:";
	std::cin>>n;
	std::cout<<"\nEnter the cost adjacency matrix:\n";
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			std::cin>>cost[i][j];
			if(cost[i][j]==0)
				cost[i][j]=99;
		}
	}
	std::cout<<"The edges of Minimum Cost Spanning Tree are\n";
	while(ne < n)
	{
		for(i=1,min=999;i<=n;i++)
		{
			for(j=1;j <= n;j++)
			{
				if(cost[i][j] < min)
				{
					min=cost[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}
		u=find(u);
		v=find(v);
		if(uni(u,v))
		{
			std::cout<<ne++<<" edge "<<a<<","<<b<<" ="<<min<<"\n";
			mincost +=min;
		}
		cost[a][b]=cost[b][a]=999;
	}
	std::cout<<"\n\tMinimum cost ="<<mincost<<"\n";
    return 0;
}
int find(int i)
{
	while(parent[i])
	i=parent[i];
	return i;
}
int uni(int i,int j)
{
	if(i!=j)
	{
		parent[j]=i;
		return 1;
	}
	return 0;
}
