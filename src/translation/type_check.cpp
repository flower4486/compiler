/*****************************************************
 *  Implementation of the second semantic analysis pass.
 *
 *  In the second pass, we will check:
 *    1. whether all the expressions are well-typed; (and sets ATTR(type))
 *    2. whether all the statements are well-formed;
 *    3. . whether all the referenced symbols are well-defined(and sets
 * ATTR(sym))
 *
 *  Keltin Leung 
 */

#include "3rdparty/list.hpp"
#include "ast/ast.hpp"
#include "ast/visitor.hpp"
#include "compiler.hpp"
#include "config.hpp"
#include "scope/scope_stack.hpp"
#include "symb/symbol.hpp"
#include "type/type.hpp"

using namespace mind;
using namespace mind::type;
using namespace mind::scope;
using namespace mind::symb;
using namespace mind::util;
using namespace mind::err;

/* Pass 2 of the semantic analysis.
 */
class SemPass2 : public ast::Visitor {
    // Visiting expressions
    virtual void visit(ast::AssignExpr *);
    virtual void visit(ast::AddExpr *);

    //增加SubExpr,MulExpr,DivExpr,ModExpr;
    virtual void visit(ast::SubExpr *);
    virtual void visit(ast::MulExpr *);
    virtual void visit(ast::DivExpr *);
    virtual void visit(ast::ModExpr *);

    //完成step3
    virtual void visit(ast::LesExpr *);
    virtual void visit(ast::GrtExpr *);
    virtual void visit(ast::LeqExpr *);
    virtual void visit(ast::GeqExpr *);
    virtual void visit(ast::EquExpr *);
    virtual void visit(ast::NeqExpr *);
    virtual void visit(ast::AndExpr *);
    virtual void visit(ast::OrExpr *);

    virtual void visit(ast::IntConst *);
    virtual void visit(ast::NegExpr *);

    virtual void visit(ast::FNegExpr *);
    //增加NotExpr,BitNotExpr;
    virtual void visit(ast::NotExpr *);
    virtual void visit(ast::BitNotExpr *);

    virtual void visit(ast::LvalueExpr *);
    virtual void visit(ast::VarRef *);
    // Visiting statements
    virtual void visit(ast::VarDecl *);
    virtual void visit(ast::CompStmt *);
    virtual void visit(ast::ExprStmt *);
    virtual void visit(ast::IfStmt *);
    virtual void visit(ast::ReturnStmt *);
    virtual void visit(ast::WhileStmt *);
    virtual void visit(ast::DoWhileStmt *);
    virtual void visit(ast::ForStmt *);
    // Visiting declarations
    virtual void visit(ast::FuncDefn *);
    virtual void visit(ast::Program *);
    virtual void visit(ast::IfExpr *s);

    virtual void visit(ast::CallExpr *s);
    virtual void visit(ast::IndexExpr *s);
};

// recording the current return type
static Type *retType = NULL;
// recording the current "this" type

/* Determines whether a given type is BaseType::Error.
 *
 * NOTE:
 *   don't use the == operator when comparing types
 * PARAMETERS:
 *   t     - the type to check
 */
static bool isErrorType(Type *t) { return t->equal(BaseType::Error); }

/* Checks whether an ast::Expr conforms to the expecting type.
 *
 * NOTE:
 *   if the expression type is BaseType::Error, we accept it as a legal case.
 * PARAMETERS:
 *   e     - the ast::Expr node
 *   t     - the expected type
 * SIDE-EFFECTS:
 *   Unexpected Type Error may be issued
 */
static void expect(ast::Expr *e, Type *t) {
    // if (!e->ATTR(type)->equal(t) && !isErrorType(e->ATTR(type))) {
    //     issue(e->getLocation(), new UnexpectedTypeError(t, e->ATTR(type)));
    // }
}

/* Visits an ast::IntConst node.
 *
 * PARAMETERS:
 *   e     - the ast::IntConst node
 */
void SemPass2::visit(ast::IntConst *e) { e->ATTR(type) = BaseType::Int;}


/* SemPass2 an ast::LesExpr node.
 */
void SemPass2::visit(ast::LesExpr *e) {
    e->e1->accept(this);
    expect(e->e1, BaseType::Int);

    e->e2->accept(this);
    expect(e->e2, BaseType::Int);

    e->ATTR(type) = BaseType::Int;
}

/* SemPass2 an ast::GrtExpr node.
 */
void SemPass2::visit(ast::GrtExpr *e) {
    e->e1->accept(this);
    expect(e->e1, BaseType::Int);

    e->e2->accept(this);
    expect(e->e2, BaseType::Int);
    
    e->ATTR(type) = BaseType::Int;
}

/* SemPass2 an ast::LeqExpr node.
 */
void SemPass2::visit(ast::LeqExpr *e) {
    e->e1->accept(this);
    expect(e->e1, BaseType::Int);

    e->e2->accept(this);
    expect(e->e2, BaseType::Int);
   
    e->ATTR(type) = BaseType::Int;
}

/* SemPass2 an ast::GeqExpr node.
 */
void SemPass2::visit(ast::GeqExpr *e) {
    e->e1->accept(this);
    expect(e->e1, BaseType::Int);

    e->e2->accept(this);
    expect(e->e2, BaseType::Int);
   
    e->ATTR(type) = BaseType::Int;
}


/* SemPass2 an ast::EquExpr node.
 */
void SemPass2::visit(ast::EquExpr *e) {
    e->e1->accept(this);
    expect(e->e1, BaseType::Int);

    e->e2->accept(this);
    expect(e->e2, BaseType::Int);
    
    e->ATTR(type) = BaseType::Int;
}

/* SemPass2 an ast::NeqExpr node.
 */
void SemPass2::visit(ast::NeqExpr *e) {
    e->e1->accept(this);
    expect(e->e1, BaseType::Int);

    e->e2->accept(this);
    expect(e->e2, BaseType::Int);
    
    e->ATTR(type) = BaseType::Int;
}

/* SemPass2 an ast::AndExpr node.
 */
void SemPass2::visit(ast::AndExpr *e) {
    e->e1->accept(this);
    expect(e->e1, BaseType::Int);

    e->e2->accept(this);
    expect(e->e2, BaseType::Int);

    e->ATTR(type) = BaseType::Int;
}

/* SemPass2 an ast::OrExpr node.
 */
void SemPass2::visit(ast::OrExpr *e) {
    e->e1->accept(this);
    expect(e->e1, BaseType::Int);

    e->e2->accept(this);
    expect(e->e2, BaseType::Int);

    e->ATTR(type) = BaseType::Int;
}


/*step2 
 *Visits an ast::AddExpr node.
 *
 * PARAMETERS:
 *   e     - the ast::AddExpr node
 */
void SemPass2::visit(ast::AddExpr *e) {
    e->e1->accept(this);
    expect(e->e1, BaseType::Int);

    e->e2->accept(this);
    expect(e->e2, BaseType::Int);

    e->ATTR(type) = BaseType::Int;
}

/*step2 
 *Visits an ast::SubExpr node.
 *
 * PARAMETERS:
 *   e     - the ast::SubExpr node
 */
void SemPass2::visit(ast::SubExpr *e) {
    e->e1->accept(this);
    expect(e->e1, BaseType::Int);

    e->e2->accept(this);
    expect(e->e2, BaseType::Int);

    e->ATTR(type) = BaseType::Int;
}

/*step2 
 *Visits an ast::MulExpr node.
 *
 * PARAMETERS:
 *   e     - the ast::MulExpr node
 */
void SemPass2::visit(ast::MulExpr *e) {
    e->e1->accept(this);
    expect(e->e1, BaseType::Int);

    e->e2->accept(this);
    expect(e->e2, BaseType::Int);

    e->ATTR(type) = BaseType::Int;
}

/*step2 
 *Visits an ast::DivExpr node.
 *
 * PARAMETERS:
 *   e     - the ast::DivExpr node
 */
void SemPass2::visit(ast::DivExpr *e) {
    e->e1->accept(this);
    expect(e->e1, BaseType::Int);

    e->e2->accept(this);
    expect(e->e2, BaseType::Int);

    e->ATTR(type) = BaseType::Int;
}

/*step2
 * Visits an ast::AddEModExprxpr node.
 *
 * PARAMETERS:
 *   e     - the ast::ModExpr node
 */
void SemPass2::visit(ast::ModExpr *e) {
    e->e1->accept(this);
    expect(e->e1, BaseType::Int);

    e->e2->accept(this);
    expect(e->e2, BaseType::Int);
 
    e->ATTR(type) = BaseType::Int;
}

/* step1
 *   Visits an ast::NegExpr node.
 *
 * PARAMETERS:
 *   e     - the ast::NegExpr node
 */
void SemPass2::visit(ast::NegExpr *e) {
    e->e->accept(this);
    expect(e->e, BaseType::Int);

    e->ATTR(type) = BaseType::Int;
}


void SemPass2::visit(ast::FNegExpr *e) {
    e->e->accept(this);
    expect(e->e, BaseType::Int);

    e->ATTR(type) = BaseType::Int;
}
/*step1 
 *Visits an ast::NotExpr node.
 *
 * PARAMETERS:
 *   e     - the ast::NotExpr node
 */
void SemPass2::visit(ast::NotExpr *e) {
    e->e->accept(this);
    expect(e->e, BaseType::Int);

    e->ATTR(type) = BaseType::Int;
}

/*step1 
 *Visits an ast::BitNotExpr node.
 *
 * PARAMETERS:
 *   e     - the ast::BitNotExpr node
 */
void SemPass2::visit(ast::BitNotExpr *e) {
    e->e->accept(this);
    expect(e->e, BaseType::Int);
 
    e->ATTR(type) = BaseType::Int;
}

/* Visits an ast::LvalueExpr node.
 *
 * PARAMETERS:
 *   e     - the ast::LvalueExpr node
 */
void SemPass2::visit(ast::LvalueExpr *e) {
    e->lvalue->accept(this);
    e->ATTR(type) = e->lvalue->ATTR(type);
   
}

/* Visits an ast::VarRef node.
 *
 * PARAMETERS:
 *   e     - the ast::VarRef node
 */

void SemPass2::visit(ast::IndexExpr *e) {
    e->ATTR(dim1)=new ast::DimList();
    for(auto c : *(e->expr_list)){
        c->accept(this);

        e->ATTR(dim1)->append(c->ATTR(value));
    }
        
}
void SemPass2::visit(ast::AssignExpr *s) {
   s->left->accept(this);
    s->e->accept(this);
     if(((ast::VarRef *)s->left)->ATTR(sym)->iscon){
         issue(s->getLocation(),
              new IncompatibleError(s->left->ATTR(type), s->e->ATTR(type)));
     }
    if ((s->left->ATTR(lv_kind)!=ast::Lvalue::ARRAY_ELE)&&!isErrorType(s->left->ATTR(type)) &&
        !s->e->ATTR(type)->compatible(s->left->ATTR(type))) {
        issue(s->getLocation(),
              new IncompatibleError(s->left->ATTR(type), s->e->ATTR(type)));
    }
    ast::VarRef *lin=((ast::VarRef *)s->left);
    Symbol *v = scopes->lookup(lin->var, lin->getLocation());
    if (NULL == v) {
        issue(lin->getLocation(), new SymbolNotFoundError(lin->var));
        return;

    } else if (!v->isVariable()) {
        issue(lin->getLocation(), new NotVariableError(v));
        return;

    } else{
        
        if(lin->ldim==NULL){
            
        }
        else{

        }
    }
    // s->left->value=s->e->ATTR(value);
    s->ATTR(type) = s->left->ATTR(type);
}
void SemPass2::visit(ast::VarRef *ref) {
    // CASE I: owner is NULL ==> referencing a local var or a member var?
    Symbol *v = scopes->lookup(ref->var, ref->getLocation());
    if (NULL == v) {
        issue(ref->getLocation(), new SymbolNotFoundError(ref->var));
        goto issue_error_type;

    } else if (!v->isVariable()) {
        issue(ref->getLocation(), new NotVariableError(v));
        goto issue_error_type;

    } else {
        ref->ATTR(sym) = (Variable *)v;
        
        if(ref->ldim==NULL){
            ref->ATTR(type) = v->getType();

            if (((Variable *)v)->isLocalVar()) {
                ref->ATTR(lv_kind) = ast::Lvalue::SIMPLE_VAR;
            }
        }
        else{
            ref->ldim->accept(this);
            // if(ref->ldim->ATTR(dim1)->length()!=((ArrayType *)v->getType())->getDim())
            //     goto issue_error_type;
            // for(auto it=ref->ldim->ATTR(dim1)->begin(),mt=((Variable *)v)->dim->begin();it!=ref->ldim->ATTR(dim1)->end();it++){
            //     if((*it)>=(*mt)) goto issue_error_type;
            //     mt++;
            // }
            // ref->ATTR(type) =v->getType();
            ref->ATTR(type) = ((ArrayType *)v->getType())->getElementType();
            ref->ldim->ATTR(dim) = ref->ATTR(sym)->getDimList();
            ref->ATTR(lv_kind) = ast::Lvalue::ARRAY_ELE;
            

        }
        // ref->ATTR(type) = v->getType();
        // ref->ATTR(sym) = (Variable *)v;

        // if (((Variable *)v)->isLocalVar()) {
        //     ref->ATTR(lv_kind) = ast::Lvalue::SIMPLE_VAR;
        // }
    }

    return;

    // sometimes "GOTO" will make things simpler. this is one of such cases:
issue_error_type:
    ref->ATTR(type) = BaseType::Error;
    ref->ATTR(sym) = NULL;
    return;
}

void SemPass2::visit(ast::CallExpr *ref) {
    // CASE I: owner is NULL ==> referencing a local var or a member var?

    //检查函数名是否被定义
    
    Function *v = (Function *)scopes->lookup(ref->name, ref->getLocation());
    util::List<Type *>::iterator iter1 = v->getType()->getArgList()->begin();//函数定义时存储的形参数类型,放在这里防止goto报错
    if (NULL == v) {
        issue(ref->getLocation(), new SymbolNotFoundError(ref->name));
        goto issue_error_type;

    } else if (!v->isFunction()) {
        issue(ref->getLocation(), new NotVariableError(v));
        goto issue_error_type;

    } else {
        ref->ATTR(type) = v->getResultType(); //函数的返回类型
        ref->ATTR(sym) = v;
    }
    if(!(ref->name=="getint"||
        ref->name=="getch"||
        ref->name=="getarray"||
        ref->name=="putint"||
        ref->name=="putch"||
        ref->name=="putarray"||
        ref->name=="starttime"||
        ref->name=="stoptime"))
        {
        if(ref->elist->length()!=v->getType()->numOfParameters())
        {
                issue(ref->getLocation(),new SymbolNotFoundError(ref->name));
        }
        for(auto item:*(ref->elist))
        {
            item->accept(this);
            expect(item,*iter1);
            ++iter1;
        }
        }
    else{
        for(auto item:*(ref->elist)){
                    item->accept(this);
                    // expect(item,*iter1);
                    ++iter1;
            }
    }
    //检查参数的数量是否和函数定义的数量相同
    // if(ref->elist->length()!=v->getType()->numOfParameters()){
    //     issue(ref->getLocation(),new SymbolNotFoundError(ref->name));
    // }

    //检查每一个参数的类型是否一致，其实只有int，感觉不用检查，~~~~~
    
    // for(auto item:*(ref->elist)){
    //     item->accept(this);
    //     expect(item,*iter1);
    //     ++iter1;
    // }
    return;

    // sometimes "GOTO" will make things simpler. this is one of such cases:
issue_error_type:
    ref->ATTR(type) = BaseType::Error;
    ref->ATTR(sym) = NULL;
    return;
}

/* Visits an ast::VarDecl node.
 *
 * PARAMETERS:
 *   decl     - the ast::VarDecl node
 */
void SemPass2::visit(ast::VarDecl *decl) {
    if (decl->init)
        decl->init->accept(this);
    //如果他是常量
    
    if(decl->var_list!=NULL){
        for(ast::DouList::iterator it=decl->var_list->begin();
        it!=decl->var_list->end();++it){
            (*it)->accept(this);
        }
    }    
}

/* Visits an ast::AssignStmt node.
 *
 * PARAMETERS:
 *   e     - the ast::AssignStmt node
 */


/* Visits an ast::ExprStmt node.
 *
 * PARAMETERS:
 *   e     - the ast::ExprStmt node
 */
void SemPass2::visit(ast::ExprStmt *s) { s->e->accept(this); }

/* Visits an ast::IfStmt node.
 *
 * PARAMETERS:
 *   e     - the ast::IfStmt node
 */
void SemPass2::visit(ast::IfStmt *s) {
    s->condition->accept(this);
    if (!s->condition->ATTR(type)->equal(BaseType::Int)) {
        issue(s->condition->getLocation(), new BadTestExprError());
        
    }

    s->true_brch->accept(this);
    s->false_brch->accept(this);
}

void SemPass2::visit(ast::IfExpr *s) {
    s->condition->accept(this);
    if (!s->condition->ATTR(type)->equal(BaseType::Int)) {
        issue(s->condition->getLocation(), new BadTestExprError());
        ;
    }
    s->true_brch->accept(this);
    expect(s->true_brch, BaseType::Int);
    s->false_brch->accept(this);
    expect(s->false_brch, BaseType::Int);

    s->ATTR(type)= BaseType::Int;
}
/* Visits an ast::CompStmt node.
 *
 * PARAMETERS:
 *   c     - the ast::CompStmt node
 */
void SemPass2::visit(ast::CompStmt *c) {
    scopes->open(c->ATTR(scope));
    for (auto it = c->stmts->begin(); it != c->stmts->end(); ++it)
        (*it)->accept(this);
    scopes->close();
}
/* Visits an ast::WhileStmt node.
 *
 * PARAMETERS:
 *   e     - the ast::WhileStmt node
 */
void SemPass2::visit(ast::WhileStmt *s) {
    s->condition->accept(this);
    if (!s->condition->ATTR(type)->equal(BaseType::Int)) {
        issue(s->condition->getLocation(), new BadTestExprError());
    }

    s->loop_body->accept(this);
}

void SemPass2::visit(ast::DoWhileStmt *s) {
    s->loop_body->accept(this);
    s->condition->accept(this);
    if (!s->condition->ATTR(type)->equal(BaseType::Int)) {
        issue(s->condition->getLocation(), new BadTestExprError());
    }
}

void SemPass2::visit(ast::ForStmt *s) {
    scopes->open(s->ATTR(scope));
    if(s->decl1!=NULL) s->decl1->accept(this);
    if(s->condition1!=NULL) s->condition1->accept(this);
    if(s->condition2!=NULL){
        s->condition2->accept(this);
        if (!s->condition2->ATTR(type)->equal(BaseType::Int)) {
            issue(s->condition2->getLocation(), new BadTestExprError());
        }
    }
    s->loop_body->accept(this);
    if(s->condition3!=NULL) s->condition3->accept(this);
    scopes->close();
}
/* Visits an ast::ReturnStmt node.
 *
 * PARAMETERS:
 *   e     - the ast::ReturnStmt node
 */
void SemPass2::visit(ast::ReturnStmt *s) {
    s->e->accept(this);

    if (!isErrorType(retType) && !s->e->ATTR(type)->compatible(retType)) {
        issue(s->e->getLocation(),
              new IncompatibleError(retType, s->e->ATTR(type)));
    }
}

/* Visits an ast::FunDefn node.
 *
 * PARAMETERS:
 *   e     - the ast::FunDefn node
 */
void SemPass2::visit(ast::FuncDefn *f) {
    ast::StmtList::iterator it;

    retType = f->ret_type->ATTR(type);

    scopes->open(f->ATTR(sym)->getAssociatedScope());
    for (it = f->stmts->begin(); it != f->stmts->end(); ++it)
        (*it)->accept(this);
    scopes->close();
}

/* Visits an ast::Program node.
 *
 * PARAMETERS:
 *   e     - the ast::Program node
 */
void SemPass2::visit(ast::Program *p) {
    scopes->open(p->ATTR(gscope));
    for (auto it = p->func_and_globals->begin();
         it != p->func_and_globals->end(); ++it)
        (*it)->accept(this);
    scopes->close(); // close the global scope
}

/* Checks the types of all the expressions.
 *
 * PARAMETERS:
 *   tree  - AST of the program
 */
void MindCompiler::checkTypes(ast::Program *tree) {
    tree->accept(new SemPass2());
}
