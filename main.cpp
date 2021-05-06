#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void fn_Layout(std::string s_Msg);

struct Alpha{
    char c_Alp;
    int i_Times;
};

struct sr_Sort{
    bool operator()(Alpha& o_Fir, Alpha& o_Sec){
        if(o_Fir.i_Times > o_Sec.i_Times){
            return true;
        }
        else if(o_Fir.i_Times == o_Sec.i_Times){
            if(o_Fir.c_Alp <= o_Sec.c_Alp){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
};

int main(){
    std::string s_Msg   = "";
    std::cin>>s_Msg;
    fn_Layout(s_Msg);

    return 0;
}

void fn_Layout(std::string s_Msg){
    int ia_C[26]        = {};
    int i_A             = static_cast<int>('a');
    for(int i_Ct= 0; i_Ct< s_Msg.length(); i_Ct++){
        int i_Tmp       = static_cast<int>(s_Msg[i_Ct]) - i_A;
        ia_C[i_Tmp]++;
    }

    std::vector<Alpha> obj_Con;
    for(int i_Ct= 0; i_Ct< sizeof(ia_C)/sizeof(int); i_Ct++){
        char c_Alp      = static_cast<char>((i_A + i_Ct));

        if(ia_C[i_Ct] == 0){
            continue;
        }
        obj_Con.push_back({c_Alp, ia_C[i_Ct]});
    }

    sr_Sort o_Ins;
    std::sort(obj_Con.begin(), obj_Con.end(), o_Ins);

    for(std::vector<Alpha>::iterator op_1L = obj_Con.begin();
        op_1L != obj_Con.end();
        op_1L ++){
        std::cout<< op_1L->c_Alp << ":" << op_1L->i_Times <<"\n";
    }
}
