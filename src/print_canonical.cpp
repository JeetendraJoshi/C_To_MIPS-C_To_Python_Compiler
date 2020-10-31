#include "ast.hpp"
#include <fstream>



int main(int argc, char* argv[])
{   
    FILE *yyout;
    std::ofstream outputFile;


    yyin = fopen(argv[2], "r");
    const Expression *ast=parseAST();
    outputFile.open(argv[4]);

    if (static_cast<std::string> (argv[1]) == "--translate"){
        std::vector<std::string> globals;
        struct context n;
        n.tabnumber = 0;
        n.globaldec = false;
        globals.clear();
        ast->printpython(outputFile, n, globals);
        
    }

    if (static_cast<std::string>(argv[1])== "-S"){
        //
        struct mipscontext n;
        n.stackstart = 0;
        n.global = true;
        n.funcDec = 0;
        std::vector<std::string> globals;
        n.mainbool = false;
        n.findSize = false;
        n.leftHand = false;
        n.isArray = false;
        n.isGlobal = false;
        n.isAssign = false;
        n.isEnum = false;
        n.initFunc = false;
        n.enumInt  = 0;
        n.registercounter = 0;
        n.vartoadd.clear();
        globals.clear();
        n.labelcounter = 0;
        n.latestloopend.clear();
        n.latestloopstart.clear();
        n.whatever = false;

        n.caseid = 0;
        n.maxlabelcounter = 0;
        n.casenumber = false;
        n.default_ = false;
        n.caseexpressions.clear();
        n.switchcounter = 0;
        n.secondswitch = false;
        n.result = 0;
        n.realsize = false;
        //outputFile<< "addi $sp, $sp, -10000"<<std::endl;
        //outputFile<< "j main"<< std::endl;
        outputFile << ".data"<<std::endl;
        ast->printmips(outputFile, n, globals);
        //if (!n.mainbool){
          //  outputFile<< "main:" << std::endl;
        //}
        //outputFile<< "end:"<<std::endl;
    }
    
    outputFile.close();


  
    return 0;
}


