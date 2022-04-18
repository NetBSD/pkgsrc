$NetBSD: patch-src_3rdparty_chromium_base_files_file__path__unittest.cc,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/base/files/file_path_unittest.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/base/files/file_path_unittest.cc
@@ -1149,7 +1149,7 @@ TEST_F(FilePathTest, FromUTF8Unsafe_And_
       "\xEF\xBC\xA1\xEF\xBC\xA2\xEF\xBC\xA3.txt" },
   };
 
-#if !defined(SYSTEM_NATIVE_UTF8) && (defined(OS_LINUX) || defined(OS_CHROMEOS))
+#if !defined(SYSTEM_NATIVE_UTF8) && (defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD))
   ScopedLocale locale("en_US.UTF-8");
 #endif
 
