int main(int argc, char *argv[]) {
	int a,b,i;
	scanf("%i %i",&a,&b);
	//for(i=0;i<=b;i++);
	if (a&&b==1){
		printf("one\n");
	}if (a&&b ==2){
		printf("two\n");
	}if (a&&b==3){
		printf("three\n");
	}if (a||b==4){
		printf("four\n");
	}if (a||b==5){
		printf("five\n");
	}if (a||b==6){
		printf("six\n");
	}if (a||b==7){
		printf("seven\n");
	}if (a||b==8){
		printf("eight\n");
	}if (a||b==9){
		printf("nine\n");
	}if (a||b>9){
		printf("Grater than 9 ");
	}
	if (a||b%2==0){
		printf("even");
	}else{
		printf("odd");
	}
	
	//}
	return 0;
}

