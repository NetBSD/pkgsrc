$NetBSD: patch-toolkit_components_osfile_modules_osfile__unix__front.jsm,v 1.6 2016/12/03 09:58:26 ryoon Exp $

--- toolkit/components/osfile/modules/osfile_unix_front.jsm.orig	2016-05-12 17:13:27.000000000 +0000
+++ toolkit/components/osfile/modules/osfile_unix_front.jsm
@@ -399,7 +399,7 @@
        throw_on_negative("statvfs",  (UnixFile.statvfs || UnixFile.statfs)(sourcePath, fileSystemInfoPtr));
 
        let bytes = new Type.uint64_t.implementation(
-                        fileSystemInfo.f_bsize * fileSystemInfo.f_bavail);
+                        fileSystemInfo.f_frsize * fileSystemInfo.f_bavail);
 
        return bytes.value;
      };
