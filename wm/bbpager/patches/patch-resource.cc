$NetBSD: patch-resource.cc,v 1.1 2015/07/17 04:53:28 bsiegert Exp $

--- resource.cc.orig	2015-07-17 04:49:35.000000000 +0000
+++ resource.cc
@@ -148,6 +148,7 @@ void Resource::SizeAndPosition() {
        columns=1;
      else {
        position.vertical=True;
+       position.horizontal=False;
        if (columns==0) columns=1;
      }
   }
@@ -159,6 +160,7 @@ void Resource::SizeAndPosition() {
     if (sscanf(value.addr, "%u", &rows) != 1)
       rows=1;
     else {
+      position.vertical=False;
       position.horizontal=True;
       if (rows==0) rows=1;
     }
