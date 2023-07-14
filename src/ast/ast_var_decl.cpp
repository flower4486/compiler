/*****************************************************
 *  Implementation of "VarDecl".
 *
 *  Please refer to ast/ast.hpp for the definition.
 *
 *  Keltin Leung 
 */

#include "ast/ast.hpp"
#include "ast/visitor.hpp"
#include "config.hpp"

using namespace mind;
using namespace mind::ast;
Type *mind::quanju=NULL;
/* Creates a new VarDecl node.
 *
 * PARAMETERS:
 *   n       - name of the variable
 *   t       - type of the variable
 *   l       - position in the source text
 */
VarDecl::VarDecl(std::string n, Type *t, DouList *li,Location *l) {

    setBasicInfo(VAR_DECL, l);
    name = n;
    type = t;
    //quanju = t;
    init = NULL;
    const1=0;
    var_list=li;
    if(var_list!=NULL){
        for(ast::DouList::iterator it=var_list->begin();
        it!=var_list->end();++it){
            (*it)->type=t;
        }
    }
    ldim=NULL;
}

VarDecl::VarDecl(std::string n, Type *t, Expr *i, DouList *li,Location *l) {
    setBasicInfo(VAR_DECL, l);

    name = n;
    type = t;
    //quanju=t;
    const1=0;
    init = i;
    var_list=li;
    if(var_list!=NULL){
        for(ast::DouList::iterator it=var_list->begin();
        it!=var_list->end();++it){
            (*it)->type=t;
        }
    }
    ldim=NULL;
}

VarDecl::VarDecl(std::string n, Location *l) {

    setBasicInfo(VAR_DECL, l);
    name = n;
    //type = quanju;
    type = NULL;
    init = NULL;
    var_list=NULL;
    const1=0;
}

VarDecl::VarDecl(std::string n, Expr *i, Location *l) {
    setBasicInfo(VAR_DECL, l);
    name = n;
    //type = quanju;
    type = NULL;
    init = i;
    var_list=NULL;
    const1=0;
}


VarDecl::VarDecl(std::string n, Type *t, Location *l) {

    setBasicInfo(VAR_DECL, l);

    name = n;
    type = t;
    init = NULL;
    
    var_list=NULL;
    const1=0;
}
VarDecl::VarDecl(std::string a,std::string n, Type *t, Location *l) {

    setBasicInfo(VAR_DECL, l);
    isparameter=1;
    name = n;
    type = t;
    init = NULL;
    
    var_list=NULL;
    const1=0;
}
VarDecl::VarDecl(std::string n, Type *t, IndexExpr * ld,DimList1 *rd, DouList *li,Location *l) {

    setBasicInfo(VAR_DECL, l);

    name = n;
    type = t;
    init = NULL;
    ldim=ld;
    rdim=rd;
    var_list=li;
    const1=0;
    if(var_list!=NULL){
        for(ast::DouList::iterator it=var_list->begin();it!=var_list->end();it++){
            (*it)->type=t;
        }
    }
}

VarDecl::VarDecl(std::string n, Type *t, IndexExpr * ld, DouList *li,Location *l) {

    setBasicInfo(VAR_DECL, l);

    name = n;
    type = t;
    init = NULL;
    ldim=ld;
    rdim=NULL;
    var_list=li;
    const1=0;
    if(var_list!=NULL){
        for(ast::DouList::iterator it=var_list->begin();it!=var_list->end();it++){
            (*it)->type=t;
        }
    }
}

VarDecl::VarDecl(std::string n,IndexExpr *ld,  DimList1 * rd, Location *l) {

    setBasicInfo(VAR_DECL, l);

    name = n;
    type = NULL;
    init = NULL;
    ldim=ld;
    rdim=rd;
    var_list=NULL;
    const1=0;
}


VarDecl::VarDecl(std::string n,IndexExpr *ld,  Location *l) {

    setBasicInfo(VAR_DECL, l);
 
    name = n;
    type = NULL;
    init = NULL;
    ldim=ld;
    rdim=NULL;
    var_list=NULL;
    const1=0;
}
VarDecl::VarDecl(std::string const1,std::string n, Type *t, Expr *i, DouList *li,Location *l) {

    setBasicInfo(VAR_DECL, l);

    name = n;
    type = t;
    //quanju=t;
    this->const1=1;
    init = i;
    var_list=li;
    if(var_list!=NULL){
        for(ast::DouList::iterator it=var_list->begin();
        it!=var_list->end();++it){
            (*it)->type=t;
            (*it)->const1=1;
        }
    }
}


VarDecl::VarDecl(std::string const1,std::string n, Type *t, IndexExpr * ld,DimList1 *rd, DouList *li,Location *l) {

    setBasicInfo(VAR_DECL, l);

    name = n;
    type = t;
    init = NULL;
    ldim=ld;
    rdim=rd;
    var_list=li;
    this->const1=1;
    if(var_list!=NULL){
        for(ast::DouList::iterator it=var_list->begin();it!=var_list->end();it++){
            (*it)->type=t;
            (*it)->const1=1;
        }
    }
}
/* Visits the current node.
 *
 * PARAMETERS:
 *   v       - the visitor
 */
void VarDecl::accept(Visitor *v) { v->visit(this); }

/* Prints the current AST node.
 *
 * PARAMETERS:
 *   os      - the output stream
 */
void VarDecl::dumpTo(std::ostream &os) {
    ASTNode::dumpTo(os);
    if (init == NULL) {
        os << " " << '"' << name << '"' << " " << type << ")";
    } else {
        os << " " << '"' << name << '"' << " " << type << "=";
        newLine(os);
        os << init << ")";
    }
    decIndent(os);
}
