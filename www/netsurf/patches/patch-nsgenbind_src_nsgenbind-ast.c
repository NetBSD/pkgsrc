$NetBSD: patch-nsgenbind_src_nsgenbind-ast.c,v 1.1 2016/12/04 12:41:47 martin Exp $

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

diff --git a/src/nsgenbind-ast.c b/src/nsgenbind-ast.c
index 49732a0..f78fe26 100644
--- nsgenbind/src/nsgenbind-ast.c.orig
+++ nsgenbind/src/nsgenbind-ast.c
@@ -132,6 +132,19 @@ genbind_new_node(enum genbind_node_type type, struct genbind_node *l, void *r)
         return nn;
 }
 
+struct genbind_node *
+genbind_new_number_node(enum genbind_node_type type,
+                        struct genbind_node *l,
+                        int number)
+{
+        struct genbind_node *nn;
+        nn = calloc(1, sizeof(struct genbind_node));
+        nn->type = type;
+        nn->l = l;
+        nn->r.number = number;
+        return nn;
+}
+
 
 /* exported interface defined in nsgenbind-ast.h */
 int
