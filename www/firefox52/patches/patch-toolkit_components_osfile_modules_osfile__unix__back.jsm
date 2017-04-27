$NetBSD: patch-toolkit_components_osfile_modules_osfile__unix__back.jsm,v 1.1 2017/04/27 01:55:57 ryoon Exp $

--- toolkit/components/osfile/modules/osfile_unix_back.jsm.orig	2016-07-25 20:22:06.000000000 +0000
+++ toolkit/components/osfile/modules/osfile_unix_back.jsm
@@ -228,8 +228,8 @@
          let statvfs = new SharedAll.HollowStructure("statvfs",
            Const.OSFILE_SIZEOF_STATVFS);
 
-         statvfs.add_field_at(Const.OSFILE_OFFSETOF_STATVFS_F_BSIZE,
-                        "f_bsize", Type.unsigned_long.implementation);
+         statvfs.add_field_at(Const.OSFILE_OFFSETOF_STATVFS_F_FRSIZE,
+                        "f_frsize", Type.unsigned_long.implementation);
          statvfs.add_field_at(Const.OSFILE_OFFSETOF_STATVFS_F_BAVAIL,
                         "f_bavail", Type.fsblkcnt_t.implementation);
 
