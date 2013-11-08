$NetBSD: patch-toolkit_components_osfile_osfile__unix__back.jsm,v 1.1 2013/11/08 12:51:25 ryoon Exp $

Based on martin@'s patch for firefox 27.0

* Use off_t for st_size
* Use function name for NetBSD

--- toolkit/components/osfile/osfile_unix_back.jsm.orig	2013-10-22 06:19:20.000000000 +0000
+++ toolkit/components/osfile/osfile_unix_back.jsm
@@ -173,7 +173,7 @@
          }
 
          stat.add_field_at(OS.Constants.libc.OSFILE_OFFSETOF_STAT_ST_SIZE,
-                        "st_size", Types.size_t.implementation);
+                        "st_size", Types.off_t.implementation);
          Types.stat = stat.getType();
        }
 
@@ -400,10 +400,17 @@
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
+       }
 
        UnixFile.pread =
          declareFFI("pread", ctypes.default_abi,
@@ -437,6 +444,11 @@
            declareFFI("readdir$INODE64", ctypes.default_abi,
                      /*return*/Types.null_or_dirent_ptr,
                       /*dir*/   Types.DIR.in_ptr); // For MacOS X
+       } else if (OS.Constants.Sys.Name == "NetBSD") {
+         UnixFile.readdir =
+           declareFFI("__readdir30", ctypes.default_abi,
+                      /*return*/Types.null_or_dirent_ptr,
+                      /*dir*/   Types.DIR.in_ptr); // Other Unices
        } else {
          UnixFile.readdir =
            declareFFI("readdir", ctypes.default_abi,
@@ -556,6 +568,25 @@
          UnixFile.fstat = function stat(fd, buf) {
            return fxstat(ver, fd, buf);
          };
+       } else if (OS.Constants.Sys.Name == "NetBSD") {
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
