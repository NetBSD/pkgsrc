$NetBSD: patch-src_tools_qlalr_lalr.cpp,v 1.1 2015/09/08 18:55:51 joerg Exp $

--- src/tools/qlalr/lalr.cpp.orig	2015-08-30 17:58:52.000000000 +0000
+++ src/tools/qlalr/lalr.cpp
@@ -238,11 +238,11 @@ void Grammar::buildExtendedGrammar ()
   non_terminals.insert (accept_symbol);
 }
 
-struct _Nullable: public std::unary_function<Name, bool>
+struct qt_Nullable: public std::unary_function<Name, bool>
 {
   Automaton *_M_automaton;
 
-  _Nullable (Automaton *aut):
+  qt_Nullable (Automaton *aut):
     _M_automaton (aut) {}
 
   bool operator () (Name name) const
@@ -300,7 +300,7 @@ void Automaton::buildNullables ()
 
       for (RulePointer rule = _M_grammar->rules.begin (); rule != _M_grammar->rules.end (); ++rule)
         {
-          NameList::iterator nn = std::find_if (rule->rhs.begin (), rule->rhs.end (), std::not1 (_Nullable (this)));
+          NameList::iterator nn = std::find_if (rule->rhs.begin (), rule->rhs.end (), std::not1 (qt_Nullable (this)));
 
           if (nn == rule->rhs.end ())
             changed |= nullables.insert (rule->lhs).second;
@@ -635,7 +635,7 @@ void Automaton::buildIncludesDigraph ()
                   if (! _M_grammar->isNonTerminal (*A))
                     continue;
 
-                  NameList::iterator first_not_nullable = std::find_if (dot, rule->rhs.end (), std::not1 (_Nullable (this)));
+                  NameList::iterator first_not_nullable = std::find_if (dot, rule->rhs.end (), std::not1 (qt_Nullable (this)));
                   if (first_not_nullable != rule->rhs.end ())
                     continue;
 
