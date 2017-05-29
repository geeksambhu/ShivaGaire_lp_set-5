int cmp_array(int expectation[], int reality[], int len){
  int i;
  for(i=0; i<len; i++){
    if(expectation[i] != reality[i])
      return 0;
  }
  return 1;
}

char* substr(char str[], int start, int end){
  char* strNew = malloc(sizeof(char)*(end-start+1));
  int i;
  for(i=start; i<=end; i++){
    strNew[i-start] = str[i];
  }
  strNew[i] = '\0';
  return strNew;
}
