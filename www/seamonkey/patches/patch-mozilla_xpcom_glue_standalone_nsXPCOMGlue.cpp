$NetBSD: patch-mozilla_xpcom_glue_standalone_nsXPCOMGlue.cpp,v 1.1 2014/06/22 08:54:39 ryoon Exp $

--- mozilla/xpcom/glue/standalone/nsXPCOMGlue.cpp.orig	2014-06-13 00:46:13.000000000 +0000
+++ mozilla/xpcom/glue/standalone/nsXPCOMGlue.cpp
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
