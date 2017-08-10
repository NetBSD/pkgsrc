$NetBSD: patch-xpcom_base_nsDebugImpl.cpp,v 1.3 2017/08/10 14:46:15 ryoon Exp $

--- xpcom/base/nsDebugImpl.cpp.orig	2017-07-31 16:20:53.000000000 +0000
+++ xpcom/base/nsDebugImpl.cpp
@@ -148,14 +148,20 @@ nsDebugImpl::Abort(const char* aFile, in
   return NS_OK;
 }
 
+#ifdef MOZ_RUST
 // From toolkit/library/rust/lib.rs
 extern "C" void intentional_panic(const char* message);
+#endif
 
 NS_IMETHODIMP
 nsDebugImpl::RustPanic(const char* aMessage)
 {
+#ifdef MOZ_RUST
   intentional_panic(aMessage);
   return NS_OK;
+#else
+  return NS_ERROR_NOT_IMPLEMENTED;
+#endif
 }
 
 NS_IMETHODIMP
