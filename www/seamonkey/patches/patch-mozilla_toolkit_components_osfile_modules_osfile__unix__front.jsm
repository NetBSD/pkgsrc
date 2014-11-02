$NetBSD: patch-mozilla_toolkit_components_osfile_modules_osfile__unix__front.jsm,v 1.3 2014/11/02 05:40:31 ryoon Exp $

--- mozilla/toolkit/components/osfile/modules/osfile_unix_front.jsm.orig	2014-10-14 06:36:43.000000000 +0000
+++ mozilla/toolkit/components/osfile/modules/osfile_unix_front.jsm
@@ -399,7 +399,7 @@
        throw_on_negative("statvfs",  (UnixFile.statvfs || UnixFile.statfs)(sourcePath, fileSystemInfoPtr));
 
        let bytes = new Type.uint64_t.implementation(
-                        fileSystemInfo.f_bsize * fileSystemInfo.f_bavail);
+                        fileSystemInfo.f_frsize * fileSystemInfo.f_bavail);
 
        return bytes.value;
      };
