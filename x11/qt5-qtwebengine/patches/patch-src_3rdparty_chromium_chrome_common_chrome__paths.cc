$NetBSD: patch-src_3rdparty_chromium_chrome_common_chrome__paths.cc,v 1.1 2021/08/03 21:04:34 markd Exp $

--- src/3rdparty/chromium/chrome/common/chrome_paths.cc.orig	2020-07-15 18:55:52.000000000 +0000
+++ src/3rdparty/chromium/chrome/common/chrome_paths.cc
@@ -52,14 +52,14 @@ const base::FilePath::CharType kPepperFl
     FILE_PATH_LITERAL("Internet Plug-Ins/PepperFlashPlayer");
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // The path to the external extension <id>.json files.
 // /usr/share seems like a good choice, see: http://www.pathname.com/fhs/
 const base::FilePath::CharType kFilepathSinglePrefExtensions[] =
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING)
-    FILE_PATH_LITERAL("/usr/share/google-chrome/extensions");
+    FILE_PATH_LITERAL("@PREFIX@/share/google-chrome/extensions");
 #else
-    FILE_PATH_LITERAL("/usr/share/chromium/extensions");
+    FILE_PATH_LITERAL("@PREFIX@/share/chromium/extensions");
 #endif  // BUILDFLAG(GOOGLE_CHROME_BRANDING)
 
 // The path to the hint file that tells the pepper plugin loader
@@ -205,7 +205,7 @@ bool PathProvider(int key, base::FilePat
         return false;
       break;
     case chrome::DIR_DEFAULT_DOWNLOADS_SAFE:
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
       if (!GetUserDownloadsDirectorySafe(&cur))
         return false;
       break;
@@ -505,7 +505,7 @@ bool PathProvider(int key, base::FilePat
       break;
     }
 #endif
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     case chrome::DIR_STANDALONE_EXTERNAL_EXTENSIONS: {
       cur = base::FilePath(kFilepathSinglePrefExtensions);
       break;
@@ -540,7 +540,7 @@ bool PathProvider(int key, base::FilePat
 #endif
       break;
 
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
     case chrome::DIR_NATIVE_MESSAGING:
 #if defined(OS_MACOSX)
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING)
@@ -574,7 +574,7 @@ bool PathProvider(int key, base::FilePat
       cur = cur.Append(kGCMStoreDirname);
       break;
 #endif  // !defined(OS_ANDROID)
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     case chrome::FILE_COMPONENT_FLASH_HINT:
       if (!base::PathService::Get(
               chrome::DIR_COMPONENT_UPDATED_PEPPER_FLASH_PLUGIN, &cur)) {
