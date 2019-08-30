int str_length(char s[]){
        int i;
	for(i=0; s[i] != '\n'; ++i); 	
	return i - 1;

}

