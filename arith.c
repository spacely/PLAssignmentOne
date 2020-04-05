#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>



#define MAX 100	/*maximum no. of characters*/

char stack[MAX];
int  intStack[MAX];
int top = -1;

int stack_int;
int int_top = -1;


typedef struct Node {
    char *data;
    struct Node *left, *right;
} Node;

typedef struct tree_Node{
    char data;
    struct tree_Node *left, *right;
}ast;
ast *AST ; // this is before

/*






*/

void pushVal(int val){
  if(int_top >= MAX-1){
		printf("\nStack Overflow.");
	}
	else{
		int_top++;
		intStack[int_top] = val;
	}

}

int popVal(){
  int val;
  if(int_top < 0){
    printf("stack under flow: invalid infix expression(numbers)");
		getchar();
    exit(1);
  }
  else{
    val = intStack[int_top];
    int_top--;
    return val;

	}

}


void push(char item){
	if(top >= MAX-1){
		printf("\nStack Overflow.");
	}
	else{
		top = top+1;
		stack[top] = item;
	}
}


char pop(){
	char item ;

	if(top <0){
		printf("stack under flow: invalid infix expression(character)");
		getchar();
		/* underflow may occur for invalid expression */
		/* where ( and ) are not matched */
		exit(1);
	}
	else{
		item = stack[top];
		top = top-1;
		return(item);
	}
}


int precedence(char symbol){


    if(symbol == '^'){/* exponent operator, highest precedence*/
      return(3);
    }
    else if(symbol == '*' || symbol == '/') {
      return(2);
    }

    else if(symbol == '+' || symbol == '-') {         /* lowest precedence */
      return(1);
    }
    else{
      return(0);
    }

}

int is_operator(char symbol){
	if(symbol == '^' || symbol == '*' || symbol == '+' || symbol =='-'){
		return 1;
	}
	else{
	   return 0;
	}
}





/*
int eval(node* root)  {
    // empty tree
    if (!root)
        return 0;

    // leaf node i.e, an integer
    if (!root->left && !root->right)
        return toInt(root->data);

    // Evaluate left subtree
    int l_val = eval(root->left);

    // Evaluate right subtree
    int r_val = eval(root->right);

    // Check which operator to apply
    if (root->data=="+")
        return l_val+r_val;

    if (root->data=="-")
        return l_val-r_val;

    if (root->data=="*")
        return l_val*r_val;

    if (root->data=="^")
        return pow(l_val,r_val);



    return l_val/r_val;
}
*/

void parse(char expression[], char postfix[]){


  //char *expr;
  int i = 0;
  int j = 0;
  char x;
  char item;

  //expr = strtok(expression, " ");
  push('(');
  strcat(expression,")");
  //if(expr == NULL){
  //  printf("\t '%s'\n", expr);
  //  puts("No separators found");
    //return NULL;
//  }


//printf("Just before loop\n");
item = expression[j];
//printf("Got an item %c\n",item);
  while(item != '\0'){
    //printf("\t'%s'\n",expr);
    //expr = strtok(NULL," ");


    //printf("Within while loop\n");
    if(item == '('){
      push(item);
    }
    else if(isdigit(item)){
      //printf("Digit here %c\n",item);
      postfix[i] = item;
      i++;
    }
    else if(is_operator(item) == 1){
      x = pop();
      //printf("Just popped here %c\n",x);
      while(is_operator(x) == 1 && precedence(x) > precedence(item)){
        postfix[i] = x;
        i++;
        x = pop();
      }
      push(x);
      push(item);
    }

    else if (item == ')'){
      x = pop();
      while(x != '('){
        postfix[i] = x;
        i++;
        x = pop();
      }


    }
    else {
      printf("\n Invalid expression\n");

      exit(1);

    }
j++;

item = expression[j];

  }//end of while look that read each token

postfix[j] = '\0';

}//end of parse.



int buildTree(char postfix[]){

  int i = 0;
  int j = 0;
  char *a = postfix;
  char x;
  char y;
  int m;
  int n;
int answer = 0;

for(int i=0;a[i]!='\0';i++){
    //printf("\t%c\n\n",a[i]);
    if(isdigit(a[i])){
      pushVal(a[i]-'0');

    }
    else if(a[i] == '+'){
      m = popVal();
      n = popVal();
      pushVal(n+m);
      }
      else if(a[i] == '-'){
        m = popVal();
        n = popVal();
        pushVal(n-m);
        }
      else if(a[i] == '*'){
          m = popVal();
          n = popVal();
          pushVal(n*m);
        }
        else if(a[i] == '^'){
          m = popVal();
          n = popVal();
          pushVal(pow(n,m));
          }





}
answer = popVal();
return answer;
}




int main(){
  char expression[100];
char postfix[MAX];
char infix[MAX];

int val = 0;

  	printf("\n Please enter an expression: \n");
    gets(infix);
    //fgets(expression,sizeof(expression),stdin);
    //scanf("%s",expression);

    //char x[100] = expression;
    //gets(expression);

  	//printf("=============\n");
  	//printf("%s\n", expression);
    //puts(infix);
    parse(infix,postfix);

   val = buildTree(postfix);
    //printf("%s\n  ",postfix);
    printf("Answer is %d\n\n\t",val);




  	return 0;





}
