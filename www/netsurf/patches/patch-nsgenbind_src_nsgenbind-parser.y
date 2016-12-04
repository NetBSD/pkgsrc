$NetBSD: patch-nsgenbind_src_nsgenbind-parser.y,v 1.1 2016/12/04 12:41:47 martin Exp $

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

diff --git a/src/nsgenbind-parser.y b/src/nsgenbind-parser.y
index c6b9a74..fd41c37 100644
--- nsgenbind/src/nsgenbind-parser.y.orig
+++ nsgenbind/src/nsgenbind-parser.y
@@ -138,17 +138,17 @@ add_method(struct genbind_node **genbind_ast,
         }
 
         location_node = genbind_new_node(GENBIND_NODE_TYPE_FILE,
-                                genbind_new_node(GENBIND_NODE_TYPE_LINE,
-                                                 cdata_node,
-                                                 (void *)lineno),
+                                genbind_new_number_node(GENBIND_NODE_TYPE_LINE,
+                                                        cdata_node,
+                                                        lineno),
                                          strdup(filename));
 
         /* generate method node */
         method_node = genbind_new_node(GENBIND_NODE_TYPE_METHOD,
                                  NULL,
-                                 genbind_new_node(GENBIND_NODE_TYPE_METHOD_TYPE,
+                                 genbind_new_number_node(GENBIND_NODE_TYPE_METHOD_TYPE,
                                                   location_node,
-                                                  (void *)methodtype));
+                                                  methodtype));
 
         class_node = genbind_node_find_type_ident(*genbind_ast,
                                                   NULL,
@@ -304,11 +304,11 @@ BindingArg:
         {
                 $$ = genbind_new_node(GENBIND_NODE_TYPE_METHOD,
                         NULL,
-                        genbind_new_node(GENBIND_NODE_TYPE_METHOD_TYPE,
+                        genbind_new_number_node(GENBIND_NODE_TYPE_METHOD_TYPE,
                                 genbind_new_node(GENBIND_NODE_TYPE_CDATA,
                                                  NULL,
                                                  $2),
-                                (void *)$1));
+                                $1));
         }
         ;
 
@@ -568,11 +568,11 @@ ClassArg:
         TOK_PROPERTY Modifiers TOK_IDENTIFIER ';'
         {
                 $$ = genbind_new_node(GENBIND_NODE_TYPE_PROPERTY, NULL,
-                        genbind_new_node(GENBIND_NODE_TYPE_MODIFIER,
+                        genbind_new_number_node(GENBIND_NODE_TYPE_MODIFIER,
                                 genbind_new_node(GENBIND_NODE_TYPE_IDENT,
                                                  NULL,
                                                  $3),
-                                         (void *)$2));
+                                         $2));
         }
         |
         TOK_FLAGS ClassFlags ';'
@@ -584,11 +584,11 @@ ClassArg:
         {
                 $$ = genbind_new_node(GENBIND_NODE_TYPE_METHOD,
                         NULL,
-                        genbind_new_node(GENBIND_NODE_TYPE_METHOD_TYPE,
+                        genbind_new_number_node(GENBIND_NODE_TYPE_METHOD_TYPE,
                                 genbind_new_node(GENBIND_NODE_TYPE_CDATA,
                                                  NULL,
                                                  $2),
-                                (void *)$1));
+                                $1));
         }
         ;
 
