$NetBSD: patch-xpcom_reflect_xptcall_src_md_unix_xptcstubs__gcc__x86__unix.cpp,v 1.2 2014/02/08 09:36:00 ryoon Exp $

--- xpcom/reflect/xptcall/src/md/unix/xptcstubs_gcc_x86_unix.cpp.orig	2014-01-28 04:04:07.000000000 +0000
+++ xpcom/reflect/xptcall/src/md/unix/xptcstubs_gcc_x86_unix.cpp
@@ -10,7 +10,7 @@
 #include "xptc_gcc_x86_unix.h"
 
 extern "C" {
-static nsresult ATTRIBUTE_USED
+nsresult ATTRIBUTE_USED
 __attribute__ ((regparm (3)))
 PrepareAndDispatch(uint32_t methodIndex, nsXPTCStubBase* self, uint32_t* args)
 {
