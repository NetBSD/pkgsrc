$NetBSD: patch-xpcom__reflect__xptcall__src__md__unix__xptcstubs_sparc64_openbsd.cpp,v 1.2 2013/06/26 11:32:12 ryoon Exp $

# HG changeset patch
# User Martin Husemann <martin@netbsd.org>
# Date 1370038989 -7200
# Node ID d296fcc8f3dd6254c862cdfd47a5580ee05a94f4
# Parent  52b02042b27f75acbcb2bd4822bedb00ab680e67
Bug 867914: Declare SharedStub as returning nsresult in xptcstubs_sparc64_openbsd.cpp. r=landry

Fixes a build issue on NetBSD/sparc64, no apparent fallout on OpenBSD/sparc64

diff xpcom/reflect/xptcall/src/md/unix/xptcstubs_sparc64_openbsd.cpp xpcom/reflect/xptcall/src/md/unix/xptcstubs_sparc64_openbsd.cpp
--- xpcom/reflect/xptcall/src/md/unix/xptcstubs_sparc64_openbsd.cpp.orig	2013-06-17 22:13:29.000000000 +0000
+++ xpcom/reflect/xptcall/src/md/unix/xptcstubs_sparc64_openbsd.cpp
@@ -83,7 +83,7 @@ PrepareAndDispatch(nsXPTCStubBase* self,
     return result;
 }
 
-extern "C" int SharedStub(int, int*);
+extern "C" nsresult SharedStub(int, int*);
 
 #define STUB_ENTRY(n) \
 nsresult nsXPTCStubBase::Stub##n() \
