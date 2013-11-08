$NetBSD: patch-mozilla_toolkit_components_osfile_modules_osfile__unix__back.jsm,v 1.1 2013/11/08 12:55:52 ryoon Exp $

--- mozilla/toolkit/components/osfile/modules/osfile_unix_back.jsm.orig	2013-10-29 01:21:11.000000000 +0000
+++ mozilla/toolkit/components/osfile/modules/osfile_unix_back.jsm
@@ -170,7 +170,7 @@
          }
 
          stat.add_field_at(OS.Constants.libc.OSFILE_OFFSETOF_STAT_ST_SIZE,
-                        "st_size", Types.size_t.implementation);
+                        "st_size", Types.off_t.implementation);
          Types.stat = stat.getType();
        }
 
@@ -397,10 +397,17 @@
                     /*oflags*/Types.int,
                     /*mode*/  Types.int);
 
+       if (OS.Constants.Sys.Name == "NetBSD") {
+       UnixFile.opendir =
+         declareFFI("__opendir30", ctypes.default_abi,
+                    /*return*/ Types.null_or_DIR_ptr,
+                    /*path*/   Types.path);
+       } else {
        UnixFile.opendir =
          declareFFI("opendir", ctypes.default_abi,
                     /*return*/ Types.null_or_DIR_ptr,
                     /*path*/   Types.path);
+      }
 
        UnixFile.pread =
          declareFFI("pread", ctypes.default_abi,
@@ -434,6 +441,11 @@
            declareFFI("readdir$INODE64", ctypes.default_abi,
                      /*return*/Types.null_or_dirent_ptr,
                       /*dir*/   Types.DIR.in_ptr); // For MacOS X
+       } else if (OS.Constants.Sys.Name == "NetBSD") {
+         UnixFile.readdir =
+           declareFFI("__readdir30", ctypes.default_abi,
+                      /*return*/Types.null_or_dirent_ptr,
+                      /*dir*/   Types.DIR.in_ptr);
        } else {
          UnixFile.readdir =
            declareFFI("readdir", ctypes.default_abi,
@@ -553,6 +565,26 @@
          UnixFile.fstat = function stat(fd, buf) {
            return fxstat(ver, fd, buf);
          };
+       } else if (OS.Constants.Sys.Name == "NetBSD") {
+         // NetBSD 5.0 and newer
+         UnixFile.stat =
+           declareFFI("__stat50", ctypes.default_abi,
+                      /*return*/ Types.negativeone_or_nothing,
+                      /*path*/   Types.path,
+                      /*buf*/    Types.stat.out_ptr
+                     );
+         UnixFile.lstat =
+           declareFFI("__lstat50", ctypes.default_abi,
+                      /*return*/ Types.negativeone_or_nothing,
+                      /*path*/   Types.path,
+                      /*buf*/    Types.stat.out_ptr
+                     );
+         UnixFile.fstat =
+           declareFFI("__fstat50", ctypes.default_abi,
+                      /*return*/ Types.negativeone_or_nothing,
+                      /*fd*/     Types.fd,
+                      /*buf*/    Types.stat.out_ptr
+                     );
        } else {
          // Mac OS X 32-bits, other Unix
          UnixFile.stat =
