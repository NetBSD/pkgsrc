$NetBSD: patch-src_Fl__Tree__Item.cxx,v 1.1 2016/12/16 00:08:03 joerg Exp $

Ordering a pointer with 0 doesn't make sense, so check for failing deparent.

--- src/Fl_Tree_Item.cxx.orig	2016-12-10 23:21:18.934820703 +0000
+++ src/Fl_Tree_Item.cxx
@@ -549,7 +549,7 @@ int Fl_Tree_Item::move(Fl_Tree_Item *ite
   } else {					// different parent?
     if ( to > to_parent->children() )		// try to prevent a reparent() error
       return -4;
-    if ( from_parent->deparent(from) < 0 )	// deparent self from current parent
+    if ( !from_parent->deparent(from) )	// deparent self from current parent
       return -5;
     if ( to_parent->reparent(this, to) < 0 ) {	// reparent self to new parent at position 'to'
       to_parent->reparent(this, 0);		// failed? shouldn't happen, reparent at 0
