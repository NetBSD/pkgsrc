$NetBSD: patch-toolkit_components_osfile_modules_osfile__unix__front.jsm,v 1.1 2014/11/03 12:18:32 ryoon Exp $

--- toolkit/components/osfile/modules/osfile_unix_front.jsm.orig	2014-05-29 23:31:41.000000000 +0000
+++ toolkit/components/osfile/modules/osfile_unix_front.jsm
@@ -373,7 +373,7 @@
        throw_on_negative("statvfs",  UnixFile.statvfs(sourcePath, fileSystemInfoPtr));
 
        let bytes = new Type.uint64_t.implementation(
-                        fileSystemInfo.f_bsize * fileSystemInfo.f_bavail);
+                        fileSystemInfo.f_frsize * fileSystemInfo.f_bavail);
 
        return bytes.value;
      };
