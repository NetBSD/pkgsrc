$NetBSD: patch-xpcom_reflect_xptcall_md_unix_xptcinvoke__sparc64__openbsd.cpp,v 1.1 2018/11/07 12:55:11 martin Exp $

Fix compile: adapt to recent changes

--- xpcom/reflect/xptcall/md/unix/xptcinvoke_sparc64_openbsd.cpp.orig	2018-10-31 01:08:15.000000000 +0100
+++ xpcom/reflect/xptcall/md/unix/xptcinvoke_sparc64_openbsd.cpp	2018-11-07 12:19:50.595159109 +0100
@@ -30,9 +30,9 @@
   {
     if (regCount < 5) regCount++;
 
-    if (l_s->IsPtrData())
+    if (l_s->IsIndirect())
     {
-      *l_d = (uint64_t)l_s->ptr;
+      *l_d = (uint64_t)&l_s->val;
       continue;
     }
     switch (l_s->type)
