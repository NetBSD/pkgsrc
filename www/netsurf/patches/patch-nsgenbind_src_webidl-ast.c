$NetBSD: patch-nsgenbind_src_webidl-ast.c,v 1.1 2016/12/04 12:41:47 martin Exp $

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

diff --git a/src/webidl-ast.c b/src/webidl-ast.c
index 0d908ce..a1133e3 100644
--- nsgenbind/src/webidl-ast.c.orig
+++ nsgenbind/src/webidl-ast.c
@@ -120,6 +120,7 @@ webidl_node_add(struct webidl_node *node, struct webidl_node *list)
 
 
 struct webidl_node *
+/* exported interface documented in webidl-ast.h */
 webidl_node_new(enum webidl_node_type type,
 		struct webidl_node *l,
 		void *r)
@@ -128,7 +129,21 @@ webidl_node_new(enum webidl_node_type type,
 	nn = calloc(1, sizeof(struct webidl_node));
 	nn->type = type;
 	nn->l = l;
-	nn->r.text = r;
+	nn->r.value = r;
+	return nn;
+}
+
+/* exported interface documented in webidl-ast.h */
+struct webidl_node *
+webidl_new_number_node(enum webidl_node_type type,
+                       struct webidl_node *l,
+                       int number)
+{
+	struct webidl_node *nn;
+	nn = calloc(1, sizeof(struct webidl_node));
+	nn->type = type;
+	nn->l = l;
+	nn->r.number = number;
 	return nn;
 }
 
