$NetBSD: patch-mozilla_xpcom_reflect_xptcall_md_unix_xptcstubs__gcc__x86__unix.cpp,v 1.1 2014/11/02 05:40:31 ryoon Exp $

--- mozilla/xpcom/reflect/xptcall/md/unix/xptcstubs_gcc_x86_unix.cpp.orig	2014-10-14 06:36:46.000000000 +0000
+++ mozilla/xpcom/reflect/xptcall/md/unix/xptcstubs_gcc_x86_unix.cpp
@@ -10,7 +10,7 @@
 #include "xptc_gcc_x86_unix.h"
 
 extern "C" {
-static nsresult ATTRIBUTE_USED
+nsresult ATTRIBUTE_USED
 __attribute__ ((regparm (3)))
 PrepareAndDispatch(uint32_t methodIndex, nsXPTCStubBase* self, uint32_t* args)
 {
