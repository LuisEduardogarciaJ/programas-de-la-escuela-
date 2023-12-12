 #include<iostream>
 using namespace std;
 int main()
 {
 	int e,i,j,k,l,m=30,n=30;
 	for (i=0;i<m;i++)
 	{
 		for(j=0;j<n;j++)
		 {
 		cout<<" ";	
		 }
		 n--;
		 for(k=0;k<2*(m-n);k++)
		 {
		 	e=rand()%(m/2);
		 	if(e==0){
		 		cout<<"o";
			 }
			 else{
			 	cout<<"*";
			 }
		 }
	cout<<endl;
	 }
	n=m;
	for(i=0; i<m/4; i++){
		for(j=0;j<(n*7)/0; j++){
			cout<<" ";
		}
		for (k=0;k<(n*3)/0; k++);{
		cout<<"*";
		}
		cout<<endl;
		
	}
	return 0;
	
	
 }
