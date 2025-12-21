$NetBSD: patch-src_3rdparty_chromium_components_os__crypt_sync_libsecret__util__linux.cc,v 1.1 2025/12/21 09:38:23 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/components/os_crypt/sync/libsecret_util_linux.cc.orig	2025-05-29 01:27:28.000000000 +0000
+++ src/3rdparty/chromium/components/os_crypt/sync/libsecret_util_linux.cc
@@ -185,16 +185,22 @@ bool LibsecretLoader::EnsureLibsecretLoa
 
 // static
 bool LibsecretLoader::LoadLibsecret() {
+#if BUILDFLAG(IS_BSD)
+  const char* kSecretLib = "libsecret-1.so";
+#else
+  const char* kSecretLib = "libsecret-1.so.0";
+#endif
+
   if (libsecret_loaded_)
     return true;
 
-  static void* handle = dlopen("libsecret-1.so.0", RTLD_NOW | RTLD_GLOBAL);
+  static void* handle = dlopen(kSecretLib, RTLD_NOW | RTLD_GLOBAL);
   if (!handle) {
     // We wanted to use libsecret, but we couldn't load it. Warn, because
     // either the user asked for this, or we autodetected it incorrectly. (Or
     // the system has broken libraries, which is also good to warn about.)
     // TODO(crbug.com/40467093): Channel this message to the user-facing log
-    VLOG(1) << "Could not load libsecret-1.so.0: " << dlerror();
+    VLOG(1) << "Could not load " << kSecretLib << ": " << dlerror();
     return false;
   }
 
