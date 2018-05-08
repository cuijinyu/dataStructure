#include <iostream>
#include <stack>
#include <string>
#include <cstdlib>
using namespace std;
class Calculator{
    public:
    Calculator(string infix):infix(infix){

    };
    ~Calculator() = default;
    void transfer_to_post(){
        //将中缀表达式转换为后缀表达式
        stack<char> operator_stack;
        char temp;//临时变量，用以存储表达式符号

        for(auto i : infix){
                 if(operator_stack.empty()){
                    if(!isNumber(i)){
                        operator_stack.push(i);
                    }else{
                        postfix += i;
                    }
                 }else{
                    temp = operator_stack.top();
                    if(isNumber(i)){
                        postfix += i;
                    }else if(i == ')'){
                        while(operator_stack.top() != '('){
                                auto data = operator_stack.top();
                                operator_stack.pop();
                                postfix += data;
                              }
                        operator_stack.pop();
                    }else if(i == '('){
                        operator_stack.push(i);
                    }else if(get_priority(i) > get_priority(operator_stack.top())){
                        operator_stack.push(i);
                    }else if(get_priority(i) <= get_priority(operator_stack.top())){
                        int i_priority = get_priority(i);
                        do{

                            try{
                                postfix += operator_stack.top();
                                operator_stack.pop();
                                if(operator_stack.empty()){
                                //当堆栈为空时，退出
                                    break;
                                }
                            }catch(exception e){
                                cout<<e.what();
                            }
                        }while(get_priority(operator_stack.top())>=i_priority);
                        operator_stack.push(i);
                    }
                 }
        }
        while(!operator_stack.empty()){
            auto data = operator_stack.top();
            operator_stack.pop();
            postfix += data;
        }

    };

    bool isNumber(char o){
        //判断是否为数字
        return (o>='0'&&o<='9');
    };
    int get_priority(char o){
        switch(o){
            case '#':
                return 0;
            case '(':
                return 1;
            case '+':
                return 2;
            case '-':
                return 2;
            case '*':
                return 3;
            case '/':
                return 3;
            case ')':
                return 4;
        }
    };

    void print(){
        cout<<postfix<<endl;
    };
    private:
        int i = 1 ;
        string infix = "";//用来存储中缀表达式
        string postfix = "" ;//用来存储后缀表达式
};

int main()
{
    //@test
    //正确结果应为：9 3 1 - 3 * + 6 2 / +
    string test = "9+(3-1)*3+6/2";
    string test_2 = "1+1*1+(1*1+1)*1";
    Calculator test_cal2(test_2);
    Calculator test_cal(test);
    test_cal.transfer_to_post();
    test_cal.print();

    //@test
    //a+b*c+(d*e+f)*g ----> abc*+de*f+g*+
    test_cal2.transfer_to_post();
    test_cal2.print();
    return 0;
}
