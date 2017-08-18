$NetBSD: patch-mozilla_toolkit_components_osfile_modules_osfile__unix__front.jsm,v 1.5 2017/08/18 23:55:07 ryoon Exp $

--- mozilla/toolkit/components/osfile/modules/osfile_unix_front.jsm.orig	2017-07-07 05:38:21.000000000 +0000
+++ mozilla/toolkit/components/osfile/modules/osfile_unix_front.jsm
@@ -399,7 +399,7 @@
        throw_on_negative("statvfs",  (UnixFile.statvfs || UnixFile.statfs)(sourcePath, fileSystemInfoPtr));
 
        let bytes = new Type.uint64_t.implementation(
-                        fileSystemInfo.f_bsize * fileSystemInfo.f_bavail);
+                        fileSystemInfo.f_frsize * fileSystemInfo.f_bavail);
 
        return bytes.value;
      };
