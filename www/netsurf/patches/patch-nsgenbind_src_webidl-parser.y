$NetBSD: patch-nsgenbind_src_webidl-parser.y,v 1.1 2016/12/04 12:41:47 martin Exp $

Backport of upstream:

commit 3b3b926d7fb92361b1e8eed2efb351c32cb7bfaa
Author: Vincent Sanders <vince@kyllikki.org>
Date:   Sun Nov 27 14:17:11 2016 +0000

    restructure AST node creation to avoid casts
    
    This changes Abstract Syntax Tree node creation for both webidl and
    genbind syntax tress. If a node is to be created with a numeric value
    instead of a pointer a separate API is now used instead of casting
    through void.
    
    This fixes parsing and AST building on big endian 64bit platforms
    where casting through void, which is completely undefined behaviour,
    generates different and non-functioning code. The solution in this
    patch is properly portable and correct without relying on casting at
    all.
    
    Thanks to James Clarke <jrtc27@jrtc27.com> for the original debugging
    and patch demonstrating how to work round the bug.

diff --git a/src/webidl-parser.y b/src/webidl-parser.y
index ec3309c..0e46b17 100644
--- nsgenbind/src/webidl-parser.y.orig
+++ nsgenbind/src/webidl-parser.y
@@ -735,9 +735,9 @@ ConstValue:
         |
         TOK_INT_LITERAL
         {
-                $$ = webidl_node_new(WEBIDL_NODE_TYPE_LITERAL_INT,
-                                     NULL,
-                                     (void *)$1);
+                $$ = webidl_new_number_node(WEBIDL_NODE_TYPE_LITERAL_INT,
+                                            NULL,
+                                            $1);
         }
         |
         TOK_NULL_LITERAL
@@ -750,16 +750,16 @@ ConstValue:
 BooleanLiteral:
         TOK_TRUE
         {
-                $$ = webidl_node_new(WEBIDL_NODE_TYPE_LITERAL_BOOL,
-                                     NULL,
-                                     (void *)true);
+                $$ = webidl_new_number_node(WEBIDL_NODE_TYPE_LITERAL_BOOL,
+                                            NULL,
+                                            (int)true);
         }
         |
         TOK_FALSE
         {
-                $$ = webidl_node_new(WEBIDL_NODE_TYPE_LITERAL_BOOL,
-                                     NULL,
-                                     (void *)false);
+                $$ = webidl_new_number_node(WEBIDL_NODE_TYPE_LITERAL_BOOL,
+                                            NULL,
+                                            (int)false);
         }
         ;
 
@@ -846,16 +846,18 @@ Attribute:
 
                 /* deal with inherit modifier */
                 if ($1) {
-                        attribute = webidl_node_new(WEBIDL_NODE_TYPE_MODIFIER,
+                        attribute = webidl_new_number_node(
+                                          WEBIDL_NODE_TYPE_MODIFIER,
                                           attribute,
-                                          (void *)WEBIDL_TYPE_MODIFIER_INHERIT);
+                                          WEBIDL_TYPE_MODIFIER_INHERIT);
                 }
 
                 /* deal with readonly modifier */
                 if ($2) {
-                        attribute = webidl_node_new(WEBIDL_NODE_TYPE_MODIFIER,
+                        attribute = webidl_new_number_node(
+                                         WEBIDL_NODE_TYPE_MODIFIER,
                                          attribute,
-                                         (void *)WEBIDL_TYPE_MODIFIER_READONLY);
+                                         WEBIDL_TYPE_MODIFIER_READONLY);
                 }
 
                 $$ = webidl_node_new(WEBIDL_NODE_TYPE_ATTRIBUTE,
@@ -880,14 +882,16 @@ StaticMemberRest:
         {
                 struct webidl_node *attribute;
 
-                attribute = webidl_node_new(WEBIDL_NODE_TYPE_MODIFIER,
-                                       $2, (void *)WEBIDL_TYPE_MODIFIER_STATIC);
+                attribute = webidl_new_number_node(WEBIDL_NODE_TYPE_MODIFIER,
+                                                   $2,
+                                                   WEBIDL_TYPE_MODIFIER_STATIC);
 
                 /* deal with readonly modifier */
                 if ($1) {
-                        attribute = webidl_node_new(WEBIDL_NODE_TYPE_MODIFIER,
+                        attribute = webidl_new_number_node(
+                                         WEBIDL_NODE_TYPE_MODIFIER,
                                          attribute,
-                                         (void *)WEBIDL_TYPE_MODIFIER_READONLY);
+                                         WEBIDL_TYPE_MODIFIER_READONLY);
                 }
 
                 $$ = webidl_node_new(WEBIDL_NODE_TYPE_ATTRIBUTE,
@@ -900,8 +904,9 @@ StaticMemberRest:
                 struct webidl_node *operation;
 
                 /* add static modifier */
-                operation = webidl_node_new(WEBIDL_NODE_TYPE_MODIFIER,
-                                       $2, (void *)WEBIDL_TYPE_MODIFIER_STATIC);
+                operation = webidl_new_number_node(WEBIDL_NODE_TYPE_MODIFIER,
+                                                   $2,
+                                                   WEBIDL_TYPE_MODIFIER_STATIC);
 
                 /* put return type on the operation */
                 operation = webidl_node_prepend($1, operation);
@@ -1015,16 +1020,16 @@ Specials:
 Special:
         TOK_GETTER
         {
-                $$ = webidl_node_new(WEBIDL_NODE_TYPE_SPECIAL,
-                                     NULL,
-                                     (void *)WEBIDL_TYPE_SPECIAL_GETTER);
+                $$ = webidl_new_number_node(WEBIDL_NODE_TYPE_SPECIAL,
+                                            NULL,
+                                            WEBIDL_TYPE_SPECIAL_GETTER);
         }
         |
         TOK_SETTER
         {
-                $$ = webidl_node_new(WEBIDL_NODE_TYPE_SPECIAL,
-                                     NULL,
-                                     (void *)WEBIDL_TYPE_SPECIAL_SETTER);
+                $$ = webidl_new_number_node(WEBIDL_NODE_TYPE_SPECIAL,
+                                            NULL,
+                                            WEBIDL_TYPE_SPECIAL_SETTER);
         }
         |
         TOK_CREATOR
@@ -1032,23 +1037,23 @@ Special:
                 /* second edition removed this special but the
                  * specifications still use it!
                  */
-                $$ = webidl_node_new(WEBIDL_NODE_TYPE_SPECIAL,
-                                     NULL,
-                                     (void *)WEBIDL_TYPE_SPECIAL_CREATOR);
+                $$ = webidl_new_number_node(WEBIDL_NODE_TYPE_SPECIAL,
+                                            NULL,
+                                            WEBIDL_TYPE_SPECIAL_CREATOR);
         }
         |
         TOK_DELETER
         {
-                $$ = webidl_node_new(WEBIDL_NODE_TYPE_SPECIAL,
-                                     NULL,
-                                     (void *)WEBIDL_TYPE_SPECIAL_DELETER);
+                $$ = webidl_new_number_node(WEBIDL_NODE_TYPE_SPECIAL,
+                                            NULL,
+                                            WEBIDL_TYPE_SPECIAL_DELETER);
         }
         |
         TOK_LEGACYCALLER
         {
-                $$ = webidl_node_new(WEBIDL_NODE_TYPE_SPECIAL,
-                                     NULL,
-                                     (void *)WEBIDL_TYPE_SPECIAL_LEGACYCALLER);
+                $$ = webidl_new_number_node(WEBIDL_NODE_TYPE_SPECIAL,
+                                            NULL,
+                                            WEBIDL_TYPE_SPECIAL_LEGACYCALLER);
         }
         ;
 
@@ -1679,8 +1684,9 @@ SingleType:
         TOK_ANY TypeSuffixStartingWithArray
         {
                 /* todo deal with TypeSuffixStartingWithArray */
-                $$ = webidl_node_new(WEBIDL_NODE_TYPE_TYPE_BASE,
-                                     NULL, (void *)WEBIDL_TYPE_ANY);
+                $$ = webidl_new_number_node(WEBIDL_NODE_TYPE_TYPE_BASE,
+                                            NULL,
+                                            WEBIDL_TYPE_ANY);
         }
         ;
 
@@ -1742,29 +1748,39 @@ NonAnyType:
         |
         TOK_STRING TypeSuffix
         {
-            $$ = webidl_node_new(WEBIDL_NODE_TYPE_TYPE_BASE, $2, (void *)WEBIDL_TYPE_STRING);
+            $$ = webidl_new_number_node(WEBIDL_NODE_TYPE_TYPE_BASE,
+                                        $2,
+                                        WEBIDL_TYPE_STRING);
         }
         |
         TOK_IDENTIFIER TypeSuffix
         {
             struct webidl_node *type;
-            type = webidl_node_new(WEBIDL_NODE_TYPE_TYPE_BASE, $2, (void *)WEBIDL_TYPE_USER);
+            type = webidl_new_number_node(WEBIDL_NODE_TYPE_TYPE_BASE,
+                                          $2,
+                                          WEBIDL_TYPE_USER);
             $$ = webidl_node_new(WEBIDL_NODE_TYPE_IDENT, type, $1);
         }
         |
         TOK_SEQUENCE '<' Type '>' Null
         {
-            $$ = webidl_node_new(WEBIDL_NODE_TYPE_TYPE_BASE, $3, (void *)WEBIDL_TYPE_SEQUENCE);
+            $$ = webidl_new_number_node(WEBIDL_NODE_TYPE_TYPE_BASE,
+                                        $3,
+                                        WEBIDL_TYPE_SEQUENCE);
         }
         |
         TOK_OBJECT TypeSuffix
         {
-            $$ = webidl_node_new(WEBIDL_NODE_TYPE_TYPE_BASE, $2, (void *)WEBIDL_TYPE_OBJECT);
+            $$ = webidl_new_number_node(WEBIDL_NODE_TYPE_TYPE_BASE,
+                                        $2,
+                                        WEBIDL_TYPE_OBJECT);
         }
         |
         TOK_DATE TypeSuffix
         {
-            $$ = webidl_node_new(WEBIDL_NODE_TYPE_TYPE_BASE, $2, (void *)WEBIDL_TYPE_DATE);
+            $$ = webidl_new_number_node(WEBIDL_NODE_TYPE_TYPE_BASE,
+                                        $2,
+                                        WEBIDL_TYPE_DATE);
         }
         ;
 
@@ -1778,7 +1794,9 @@ ConstType:
         TOK_IDENTIFIER Null
         {
             struct webidl_node *type;
-            type = webidl_node_new(WEBIDL_NODE_TYPE_TYPE_BASE, NULL, (void *)WEBIDL_TYPE_USER);
+            type = webidl_new_number_node(WEBIDL_NODE_TYPE_TYPE_BASE,
+                                          NULL,
+                                          WEBIDL_TYPE_USER);
             type = webidl_node_new(WEBIDL_NODE_TYPE_IDENT, type, $1);
             $$ = webidl_node_new(WEBIDL_NODE_TYPE_TYPE, NULL, type);
         }
@@ -1793,17 +1811,23 @@ PrimitiveType:
         |
         TOK_BOOLEAN
         {
-            $$ = webidl_node_new(WEBIDL_NODE_TYPE_TYPE_BASE, NULL, (void *)WEBIDL_TYPE_BOOL);
+            $$ = webidl_new_number_node(WEBIDL_NODE_TYPE_TYPE_BASE,
+                                        NULL,
+                                        WEBIDL_TYPE_BOOL);
         }
         |
         TOK_BYTE
         {
-            $$ = webidl_node_new(WEBIDL_NODE_TYPE_TYPE_BASE, NULL, (void *)WEBIDL_TYPE_BYTE);
+            $$ = webidl_new_number_node(WEBIDL_NODE_TYPE_TYPE_BASE,
+                                        NULL,
+                                        WEBIDL_TYPE_BYTE);
         }
         |
         TOK_OCTET
         {
-            $$ = webidl_node_new(WEBIDL_NODE_TYPE_TYPE_BASE, NULL, (void *)WEBIDL_TYPE_OCTET);
+            $$ = webidl_new_number_node(WEBIDL_NODE_TYPE_TYPE_BASE,
+                                        NULL,
+                                        WEBIDL_TYPE_OCTET);
         }
         ;
 
@@ -1811,9 +1835,9 @@ PrimitiveType:
 UnrestrictedFloatType:
         TOK_UNRESTRICTED FloatType
         {
-            $$ = webidl_node_new(WEBIDL_NODE_TYPE_MODIFIER,
-                                 $2,
-                                 (void *)WEBIDL_TYPE_MODIFIER_UNRESTRICTED);
+            $$ = webidl_new_number_node(WEBIDL_NODE_TYPE_MODIFIER,
+                                        $2,
+                                        WEBIDL_TYPE_MODIFIER_UNRESTRICTED);
         }
         |
         FloatType
@@ -1823,12 +1847,16 @@ UnrestrictedFloatType:
 FloatType:
         TOK_FLOAT
         {
-            $$ = webidl_node_new(WEBIDL_NODE_TYPE_TYPE_BASE, NULL, (void *)WEBIDL_TYPE_FLOAT);
+            $$ = webidl_new_number_node(WEBIDL_NODE_TYPE_TYPE_BASE,
+                                        NULL,
+                                        WEBIDL_TYPE_FLOAT);
         }
         |
         TOK_DOUBLE
         {
-            $$ = webidl_node_new(WEBIDL_NODE_TYPE_TYPE_BASE, NULL, (void *)WEBIDL_TYPE_DOUBLE);
+            $$ = webidl_new_number_node(WEBIDL_NODE_TYPE_TYPE_BASE,
+                                        NULL,
+                                        WEBIDL_TYPE_DOUBLE);
         }
         ;
 
@@ -1836,9 +1864,9 @@ FloatType:
 UnsignedIntegerType:
         TOK_UNSIGNED IntegerType
         {
-            $$ = webidl_node_new(WEBIDL_NODE_TYPE_MODIFIER,
-                                 $2,
-                                 (void *)WEBIDL_TYPE_MODIFIER_UNSIGNED);
+            $$ = webidl_new_number_node(WEBIDL_NODE_TYPE_MODIFIER,
+                                        $2,
+                                        WEBIDL_TYPE_MODIFIER_UNSIGNED);
         }
         |
         IntegerType
@@ -1848,15 +1876,21 @@ UnsignedIntegerType:
 IntegerType:
         TOK_SHORT
         {
-            $$ = webidl_node_new(WEBIDL_NODE_TYPE_TYPE_BASE, NULL, (void *)WEBIDL_TYPE_SHORT);
+            $$ = webidl_new_number_node(WEBIDL_NODE_TYPE_TYPE_BASE,
+                                        NULL,
+                                        WEBIDL_TYPE_SHORT);
         }
         |
         TOK_LONG OptionalLong
         {
             if ($2) {
-                $$ = webidl_node_new(WEBIDL_NODE_TYPE_TYPE_BASE, NULL, (void *)WEBIDL_TYPE_LONGLONG);
+                $$ = webidl_new_number_node(WEBIDL_NODE_TYPE_TYPE_BASE,
+                                            NULL,
+                                            WEBIDL_TYPE_LONGLONG);
             } else {
-                $$ = webidl_node_new(WEBIDL_NODE_TYPE_TYPE_BASE, NULL, (void *)WEBIDL_TYPE_LONG);
+                $$ = webidl_new_number_node(WEBIDL_NODE_TYPE_TYPE_BASE,
+                                            NULL,
+                                            WEBIDL_TYPE_LONG);
             }
         }
         ;
@@ -1927,7 +1961,9 @@ ReturnType:
         TOK_VOID
         {
             struct webidl_node *type;
-            type = webidl_node_new(WEBIDL_NODE_TYPE_TYPE_BASE, NULL, (void *)WEBIDL_TYPE_VOID);
+            type = webidl_new_number_node(WEBIDL_NODE_TYPE_TYPE_BASE,
+                                          NULL,
+                                          WEBIDL_TYPE_VOID);
             $$ = webidl_node_new(WEBIDL_NODE_TYPE_TYPE, NULL, type);
         }
 
