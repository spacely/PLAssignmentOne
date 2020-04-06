import java.util.*;
import java.lang.Math;



public class ArithParser{
  private String tokens[];
  private Stack<String> exprStack = new Stack<String>();
  private Stack<Integer> numbersStack = new Stack<Integer>();
  private StringBuilder reverse_notation = new StringBuilder();

  private List<String> reverse_notation_List = new ArrayList<String>();

  public ArithParser(String tokens[]){

    this.tokens = tokens;
  }

  public String[] parse(){
    //exprStack.push("(");

    String popped;

    exprStack.push("(");



    for(int i=0; i< tokens.length;i++){
        if(tokens[i].equals("(")){
          exprStack.push("(");
        }
        else if(isNumeric(tokens[i])){
          reverse_notation.append(tokens[i]);
          reverse_notation_List.add(tokens[i]);
        }
        else if(is_operator(tokens[i]) == true){
            popped = exprStack.pop();
            while(is_operator(popped) == true && precedence(popped) > precedence(tokens[i])){
              reverse_notation.append(popped);
              reverse_notation_List.add(popped);
              popped = exprStack.pop();

            }
            exprStack.push(popped);
            exprStack.push(tokens[i]);

        }
        else if(tokens[i].equals(")")){
          popped = exprStack.pop();
          while(popped.equals("(" ) == false ){
            reverse_notation.append(popped);
            reverse_notation_List.add(popped);
            popped = exprStack.pop();
          }

        }
        else {
          System.out.println("Invalid expression");
        }




  }
  //System.out.println(reverse_notation.toString());
  String[] parsed = reverse_notation_List.toArray(new String[reverse_notation_List.size()]);
  return parsed;
}


int precedence(String symbol){


    if(symbol.equals("^")){/* exponent operator, highest precedence*/
      return(3);
    }
    else if(symbol.equals("*") || symbol.equals("/")) {
      return(2);
    }

    else if(symbol.equals("+") || symbol.equals("-")) {         /* lowest precedence */
      return(1);
    }
    else{
      return(0);
    }

}


boolean is_operator(String symbol){
  if(symbol.equals("^") || symbol.equals("*") || symbol.equals("+") || symbol.equals("-")){
    return true;
  }
  else {
    return false;
  }


}

boolean isNumeric(String val){
boolean answer = false;
try{
    Integer.parseInt(val);
    answer = true;

}catch(NumberFormatException e){
  answer = false;
}

  return answer;
}

int eval(String RPN[]){
  int firstnumber =0;
  int secondnumber = 0;

  for(int i=0;i<RPN.length;i++){
    if(isNumeric(RPN[i])){
        int value = Integer.parseInt(RPN[i]);
        numbersStack.push(value);

    }
    else if(RPN[i].equals("+")) {
      firstnumber = numbersStack.pop();
      secondnumber = numbersStack.pop();
      numbersStack.push(secondnumber+firstnumber);


    }
    else if(RPN[i].equals("-")) {
      firstnumber = numbersStack.pop();
      secondnumber = numbersStack.pop();
      numbersStack.push(secondnumber-firstnumber);

    }
    else if(RPN[i].equals("*")) {
      firstnumber = numbersStack.pop();
      secondnumber = numbersStack.pop();
      numbersStack.push(secondnumber*firstnumber);


    }
    else if(RPN[i].equals("^")) {
      firstnumber = numbersStack.pop();
      secondnumber = numbersStack.pop();
      double a = Math.pow(secondnumber,firstnumber);
      int b = (int)Math.round(a);
      numbersStack.push(b);


    }


  }


return numbersStack.pop();
}




    public static void main(String args[]){
      System.out.println("Enter an Arith expression");
      Scanner scanner = new Scanner(System.in);
      StringBuilder sb = new StringBuilder(scanner.nextLine());
      sb.append(" ");
      sb.append(")");
      int calculated_value = 0;
      String tokens[] = sb.toString().split(" ");
      //String tokens[] = scanner.nextLine().split(" ");
      //System.out.println(Arrays.asList(tokens));
      scanner.close();

      ArithParser arith = new ArithParser(tokens);
      String RPN[] = arith.parse();
      calculated_value = arith.eval(RPN);
      System.out.println("The answer is "+calculated_value);


    }



}
