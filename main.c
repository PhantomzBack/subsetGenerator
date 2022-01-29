#include<stdio.h>
int combinations( int n, int k){
    int n_fac=1, k_fac=1, n_k_fac=1,i=1;
    for(i=1;i<=n;i++){
        n_fac=n_fac*i;
    }
    for(i=1;i<=k;i++){
        k_fac=k_fac*i;
    }
    for(i=1;i<=(n-k);i++){
        n_k_fac=n_k_fac*i;
    }
    return (n_fac)/(k_fac*n_k_fac);
}


int main(){
	int lengthSet=6,lengthSubset=4,subsetCurrent[lengthSubset], maxVal[lengthSubset], lastNotMax, allSubsets[lengthSubset][combinations(lengthSet, lengthSubset)],counter=0;
	for(int x=0;x!=lengthSubset;x++){
		maxVal[x]=lengthSet-(lengthSubset-1)+x;
		subsetCurrent[x]=x+1;
	}
	for(int i=0;subsetCurrent[0]!=maxVal[0];i++){
		for(int z=0;z!=lengthSubset;z++){
			allSubsets[z][counter]=subsetCurrent[z];
		}
		counter++;
		lastNotMax=lengthSet+1;
		for(int j=0;j!=lengthSubset;j++){
			if(subsetCurrent[lengthSubset-(j+1)]!=maxVal[lengthSubset-(j+1)]){
				lastNotMax=lengthSubset-(j+1);
				break;
			}
		}
		if(lastNotMax==lengthSet+1){
			break;
		}
		else{
			subsetCurrent[lastNotMax]++;
			for(int r=lastNotMax+1;r!=lengthSubset;r++){
				subsetCurrent[r]=subsetCurrent[r-1]+1;
			}
		}



	}
	for(int jk=0;jk!=(combinations(lengthSet, lengthSubset));jk++){
		for(int l=0;l!=lengthSubset;l++){
			printf("%d, ", allSubsets[l][jk]);
		}
		printf("\n");
	}

}
