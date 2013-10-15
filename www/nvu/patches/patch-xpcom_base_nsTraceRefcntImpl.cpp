$NetBSD: patch-xpcom_base_nsTraceRefcntImpl.cpp,v 1.1 2013/10/15 14:49:35 joerg Exp $

--- xpcom/base/nsTraceRefcntImpl.cpp.orig	2004-02-11 07:16:10.000000000 +0000
+++ xpcom/base/nsTraceRefcntImpl.cpp
@@ -1304,7 +1304,7 @@ nsTraceRefcntImpl::LogAddCOMPtr(void* aC
 {
 #if defined(NS_BUILD_REFCNT_LOGGING) && defined(HAVE_CPP_DYNAMIC_CAST_TO_VOID_PTR)
   // Get the most-derived object.
-  void *object = dynamic_cast<void *>(aObject);
+  void *object = reinterpret_cast<void *>(aObject);
 
   // This is a very indirect way of finding out what the class is
   // of the object being logged.  If we're logging a specific type,
@@ -1347,7 +1347,7 @@ nsTraceRefcntImpl::LogReleaseCOMPtr(void
 {
 #if defined(NS_BUILD_REFCNT_LOGGING) && defined(HAVE_CPP_DYNAMIC_CAST_TO_VOID_PTR)
   // Get the most-derived object.
-  void *object = dynamic_cast<void *>(aObject);
+  void *object = reinterpret_cast<void *>(aObject);
 
   // This is a very indirect way of finding out what the class is
   // of the object being logged.  If we're logging a specific type,
