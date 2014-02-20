$NetBSD: patch-xpcom_reflect_xptcall_src_md_unix_xptcstubs__gcc__x86__unix.cpp,v 1.3 2014/02/20 13:19:03 ryoon Exp $

--- xpcom/reflect/xptcall/src/md/unix/xptcstubs_gcc_x86_unix.cpp.orig	2013-05-11 19:19:56.000000000 +0000
+++ xpcom/reflect/xptcall/src/md/unix/xptcstubs_gcc_x86_unix.cpp
@@ -10,7 +10,7 @@
 #include "xptc_gcc_x86_unix.h"
 
 extern "C" {
-static nsresult ATTRIBUTE_USED
+nsresult ATTRIBUTE_USED
 __attribute__ ((regparm (3)))
 PrepareAndDispatch(uint32_t methodIndex, nsXPTCStubBase* self, uint32_t* args)
 {
