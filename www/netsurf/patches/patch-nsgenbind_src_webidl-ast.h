$NetBSD: patch-nsgenbind_src_webidl-ast.h,v 1.1 2016/12/04 12:41:47 martin Exp $

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

diff --git a/src/webidl-ast.h b/src/webidl-ast.h
index bd9b313..fad070b 100644
--- nsgenbind/src/webidl-ast.h.orig
+++ nsgenbind/src/webidl-ast.h
@@ -92,8 +92,17 @@ typedef int (webidl_callback_t)(struct webidl_node *node, void *ctx);
 
 int webidl_cmp_node_type(struct webidl_node *node, void *ctx);
 
+/**
+ * create a new node with a pointer value
+ */
 struct webidl_node *webidl_node_new(enum webidl_node_type, struct webidl_node *l, void *r);
 
+/**
+ * create a new node with an integer value
+ */
+struct webidl_node *webidl_new_number_node(enum webidl_node_type type, struct webidl_node *l, int number);
+
+
 void webidl_node_set(struct webidl_node *node, enum webidl_node_type type, void *r);
 
 struct webidl_node *webidl_node_prepend(struct webidl_node *list, struct webidl_node *node);
