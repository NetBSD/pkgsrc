$NetBSD: patch-Source_WTF_wtf_RefCountedLeakCounter.h,v 1.1 2013/05/09 14:04:42 joerg Exp $

--- Source/WTF/wtf/RefCountedLeakCounter.h.orig	2013-05-08 07:48:32.000000000 +0000
+++ Source/WTF/wtf/RefCountedLeakCounter.h
@@ -38,11 +38,7 @@ namespace WTF {
 
 #ifndef NDEBUG
     private:
-#if COMPILER(MINGW) || COMPILER(MSVC7_OR_LOWER) || OS(WINCE)
-        int m_count;
-#else
-        volatile int m_count;
-#endif
+        atomic_int m_count;
         const char* m_description;
 #endif
     };
