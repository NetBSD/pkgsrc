$NetBSD: patch-src_3rdparty_chromium_components_os__crypt_os__crypt.h,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/components/os_crypt/os_crypt.h.orig	2020-07-08 21:40:40.000000000 +0000
+++ src/3rdparty/chromium/components/os_crypt/os_crypt.h
@@ -15,7 +15,7 @@
 #include "base/strings/string16.h"
 #include "build/build_config.h"
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 class KeyStorageLinux;
 #endif  // defined(OS_LINUX) && !defined(OS_CHROMEOS)
 
@@ -34,13 +34,13 @@ struct Config;
 // true for Linux, if a password management tool is available.
 class OSCrypt {
  public:
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   // Set the configuration of OSCrypt.
   static COMPONENT_EXPORT(OS_CRYPT) void SetConfig(
       std::unique_ptr<os_crypt::Config> config);
 #endif  // defined(OS_LINUX) && !defined(OS_CHROMEOS)
 
-#if defined(OS_MACOSX) || (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+#if defined(OS_MACOSX) || ((defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS))
   // On Linux returns true iff the real secret key (not hardcoded one) is
   // available. On MacOS returns true if Keychain is available (for mock
   // Keychain it returns true if not using locked Keychain, false if using
@@ -131,7 +131,7 @@ class OSCrypt {
   DISALLOW_IMPLICIT_CONSTRUCTORS(OSCrypt);
 };
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 // For unit testing purposes, inject methods to be used.
 // |get_key_storage_mock| provides the desired |KeyStorage| implementation.
 // If the provider returns |nullptr|, a hardcoded password will be used.
