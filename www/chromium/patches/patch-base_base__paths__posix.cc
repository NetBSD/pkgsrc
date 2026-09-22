$NetBSD: patch-base_base__paths__posix.cc,v 1.26 2026/09/22 13:41:17 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/base_paths_posix.cc.orig	2026-09-14 22:17:16.000000000 +0000
+++ base/base_paths_posix.cc
@@ -26,7 +26,7 @@
 #include "base/process/process_metrics.h"
 #include "build/build_config.h"
 
-#if BUILDFLAG(IS_FREEBSD)
+#if BUILDFLAG(IS_BSD)
 #include <sys/param.h>
 #include <sys/sysctl.h>
 #elif BUILDFLAG(IS_SOLARIS) || BUILDFLAG(IS_AIX)
@@ -47,13 +47,21 @@ bool PathProviderPosix(int key, FilePath
       *result = bin_dir;
       return true;
 #elif BUILDFLAG(IS_FREEBSD)
-      int name[] = {CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1};
-      std::optional<std::string> bin_dir = StringSysctl(name, std::size(name));
+      std::optional<std::string> bin_dir = StringSysctl({ CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1 });
       if (!bin_dir.has_value() || bin_dir.value().length() <= 1) {
         NOTREACHED() << "Unable to resolve path.";
       }
       *result = FilePath(bin_dir.value());
       return true;
+#elif BUILDFLAG(IS_NETBSD)
+      std::optional<std::string> bin_dir = StringSysctl({ CTL_KERN, KERN_PROC_ARGS, getpid(), KERN_PROC_PATHNAME });
+      if (!bin_dir.has_value() || bin_dir.value().length() <= 1) {
+        NOTREACHED() << "Unable to resolve path.";
+        return false;
+      }
+      *result = FilePath(bin_dir.value());
+      VLOG(1) << "PathProviderPosix result: " << bin_dir.value();
+      return true;
 #elif BUILDFLAG(IS_SOLARIS)
       char bin_dir[PATH_MAX + 1];
       if (realpath(getexecname(), bin_dir) == NULL) {
@@ -61,13 +69,20 @@ bool PathProviderPosix(int key, FilePath
       }
       *result = FilePath(bin_dir);
       return true;
-#elif BUILDFLAG(IS_OPENBSD) || BUILDFLAG(IS_AIX)
+#elif BUILDFLAG(IS_OPENBSD) && (OpenBSD >= 202610)
+      char execpath[PATH_MAX];
+      if (getexecpath(execpath, sizeof(execpath)) != 0) {
+        NOTREACHED() << "Unable to resolve path.";
+      }
+      *result = FilePath(execpath);
+      return true;
+#elif BUILDFLAG(IS_AIX) || BUILDFLAG(IS_OPENBSD)
       // There is currently no way to get the executable path on OpenBSD
       char* cpath;
       if ((cpath = getenv("CHROME_EXE_PATH")) != NULL) {
         *result = FilePath(cpath);
       } else {
-        *result = FilePath("/usr/local/chrome/chrome");
+        *result = FilePath("@PREFIX@/lib/chromium/chrome");
       }
       return true;
 #endif
