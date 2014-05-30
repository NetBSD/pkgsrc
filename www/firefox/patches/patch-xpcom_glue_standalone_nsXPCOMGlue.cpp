$NetBSD: patch-xpcom_glue_standalone_nsXPCOMGlue.cpp,v 1.1 2014/05/30 10:22:06 pho Exp $

Replace XP_MACOSX with XP_DARWIN as the former is not defined when the
toolkit is not cocoa.

--- xpcom/glue/standalone/nsXPCOMGlue.cpp.orig	2014-05-26 07:53:46.000000000 +0000
+++ xpcom/glue/standalone/nsXPCOMGlue.cpp
@@ -119,7 +119,7 @@ CloseLibHandle(LibHandleType aLibHandle)
     DosFreeModule(aLibHandle);
 }
 
-#elif defined(XP_MACOSX)
+#elif defined(XP_DARWIN)
 #include <mach-o/dyld.h>
 
 typedef const mach_header *LibHandleType;
@@ -348,7 +348,7 @@ typedef Scoped<ScopedCloseFileTraits> Sc
 static void
 XPCOMGlueUnload()
 {
-#if !defined(XP_WIN) && !defined(XP_OS2) && !defined(XP_MACOSX) \
+#if !defined(XP_WIN) && !defined(XP_OS2) && !defined(XP_DARWIN) \
   && defined(NS_TRACE_MALLOC)
     if (sTop) {
         _malloc = __libc_malloc;
@@ -461,7 +461,7 @@ XPCOMGlueLoad(const char *xpcomFile)
         return nullptr;
     }
 
-#if !defined(XP_WIN) && !defined(XP_OS2) && !defined(XP_MACOSX) \
+#if !defined(XP_WIN) && !defined(XP_OS2) && !defined(XP_DARWIN) \
   && defined(NS_TRACE_MALLOC)
     _malloc = (__ptr_t(*)(size_t)) GetSymbol(sTop->libHandle, "malloc");
     _calloc = (__ptr_t(*)(size_t, size_t)) GetSymbol(sTop->libHandle, "calloc");
