$NetBSD: patch-chrome_common_chrome__paths.cc,v 1.1 2025/02/06 09:57:57 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/common/chrome_paths.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/common/chrome_paths.cc
@@ -30,7 +30,7 @@
 #include "base/apple/foundation_util.h"
 #endif
 
-#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_OPENBSD)
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC)
 #include "components/policy/core/common/policy_paths.h"
 #endif
 
@@ -52,14 +52,14 @@
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // The path to the external extension <id>.json files.
 // /usr/share seems like a good choice, see: http://www.pathname.com/fhs/
 const base::FilePath::CharType kFilepathSinglePrefExtensions[] =
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING)
-    FILE_PATH_LITERAL("/usr/share/google-chrome/extensions");
+    FILE_PATH_LITERAL("@PREFIX@/share/chromium/extensions");
 #else
-    FILE_PATH_LITERAL("/usr/share/chromium/extensions");
+    FILE_PATH_LITERAL("@PREFIX@/share/chromium/extensions");
 #endif  // BUILDFLAG(GOOGLE_CHROME_BRANDING)
 
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
@@ -219,7 +219,7 @@ bool PathProvider(int key, base::FilePat
       }
       break;
     case chrome::DIR_DEFAULT_DOWNLOADS_SAFE:
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       if (!GetUserDownloadsDirectorySafe(&cur)) {
         return false;
       }
@@ -535,7 +535,7 @@ bool PathProvider(int key, base::FilePat
         return false;
       }
       break;
-#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_OPENBSD)
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC)
     case chrome::DIR_POLICY_FILES: {
       cur = base::FilePath(policy::kPolicyPath);
       break;
@@ -546,7 +546,7 @@ bool PathProvider(int key, base::FilePat
 #if BUILDFLAG(IS_CHROMEOS_ASH) ||                              \
     ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) && \
      BUILDFLAG(CHROMIUM_BRANDING)) ||                          \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     case chrome::DIR_USER_EXTERNAL_EXTENSIONS: {
       if (!base::PathService::Get(chrome::DIR_USER_DATA, &cur)) {
         return false;
@@ -555,7 +555,7 @@ bool PathProvider(int key, base::FilePat
       break;
     }
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     case chrome::DIR_STANDALONE_EXTERNAL_EXTENSIONS: {
       cur = base::FilePath(kFilepathSinglePrefExtensions);
       break;
@@ -593,7 +593,7 @@ bool PathProvider(int key, base::FilePat
       break;
 
 #if BUILDFLAG(ENABLE_EXTENSIONS) && \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD))
     case chrome::DIR_NATIVE_MESSAGING:
 #if BUILDFLAG(IS_MAC)
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING)
@@ -607,6 +607,9 @@ bool PathProvider(int key, base::FilePat
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING)
       cur = base::FilePath(
           FILE_PATH_LITERAL("/etc/opt/chrome/native-messaging-hosts"));
+#elif BUILDFLAG(IS_FREEBSD) || BUILDFLAG(IS_NETBSD)
+      cur = base::FilePath(FILE_PATH_LITERAL(
+          "@PREFIX@/etc/chromium/native-messaging-hosts"));
 #else
       cur = base::FilePath(
           FILE_PATH_LITERAL("/etc/chromium/native-messaging-hosts"));
