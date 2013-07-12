$NetBSD: patch-mozilla_xpcom_reflect_xptcall_src_md_unix_xptcstubs__sparc64__openbsd.cpp,v 1.1 2013/07/12 12:24:11 ryoon Exp $

--- mozilla/xpcom/reflect/xptcall/src/md/unix/xptcstubs_sparc64_openbsd.cpp.orig	2013-06-20 04:35:24.000000000 +0000
+++ mozilla/xpcom/reflect/xptcall/src/md/unix/xptcstubs_sparc64_openbsd.cpp
@@ -83,7 +83,7 @@ PrepareAndDispatch(nsXPTCStubBase* self,
     return result;
 }
 
-extern "C" int SharedStub(int, int*);
+extern "C" nsresult SharedStub(int, int*);
 
 #define STUB_ENTRY(n) \
 nsresult nsXPTCStubBase::Stub##n() \
