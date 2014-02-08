$NetBSD: patch-toolkit_components_osfile_modules_osfile__unix__back.jsm,v 1.3 2014/02/08 09:36:00 ryoon Exp $

Based on martin@'s patch for firefox 27.0

* Use off_t for st_size
* Use function name for NetBSD

--- toolkit/components/osfile/modules/osfile_unix_back.jsm.orig	2014-01-28 04:04:04.000000000 +0000
+++ toolkit/components/osfile/modules/osfile_unix_back.jsm
@@ -380,9 +380,17 @@
                     /*oflags*/Type.int,
                     /*mode*/  Type.int);
 
+       if (OS.Constants.Sys.Name == "NetBSD") {
+       // NetBSD 5.0 uses *30, and netbsd-6 uses *50
+       let v = OS.Constants.libc.OSFILE_SIZEOF_TIME_T < 8 ? "30" : "50";
+       declareLazyFFI(SysFile,  "opendir", libc, "__opendir"+v, ctypes.default_abi,
+                    /*return*/ Type.null_or_DIR_ptr,
+                    /*path*/   Type.path);
+       } else {
        declareLazyFFI(SysFile,  "opendir", libc, "opendir", ctypes.default_abi,
                     /*return*/ Type.null_or_DIR_ptr,
                     /*path*/   Type.path);
+       }
 
        declareLazyFFI(SysFile,  "pread", libc, "pread", ctypes.default_abi,
                     /*return*/ Type.negativeone_or_ssize_t,
@@ -419,6 +427,12 @@
          declareLazyFFI(SysFile,  "readdir", libc, "readdir$INODE64", ctypes.default_abi,
                      /*return*/Type.null_or_dirent_ptr,
                       /*dir*/   Type.DIR.in_ptr); // For MacOS X
+       } else if (OS.Constants.Sys.Name == "NetBD") {
+         // NetBSD 5.0 uses *30, and netbsd-6 uses *50
+         let v = OS.Constants.libc.OSFILE_SIZEOF_TIME_T < 8 ? "30" : "50";
+         declareLazyFFI(SysFile,  "readdir", libc, "__readdir"+v, ctypes.default_abi,
+                      /*return*/Type.null_or_dirent_ptr,
+                      /*dir*/   Type.DIR.in_ptr);
        } else {
          declareLazyFFI(SysFile,  "readdir", libc, "readdir", ctypes.default_abi,
                       /*return*/Type.null_or_dirent_ptr,
@@ -529,6 +543,24 @@
          SysFile.fstat = function fstat(fd, buf) {
            return Stat.fxstat(ver, fd, buf);
          };
+       } else if (OS.Constants.Sys.Name == "NetBSD") {
+         // NetBSD 5.0 uses *30, and netbsd-6 uses *50
+         let v = OS.Constants.libc.OSFILE_SIZEOF_TIME_T < 8 ? "30" : "50";
+         declareLazyFFI(SysFile,  "stat", libc, "__stat"+v, ctypes.default_abi,
+                      /*return*/ Type.negativeone_or_nothing,
+                      /*path*/   Type.path,
+                      /*buf*/    Type.stat.out_ptr
+                     );
+         declareLazyFFI(SysFile,  "lstat", libc, "__lstat"+v, ctypes.default_abi,
+                      /*return*/ Type.negativeone_or_nothing,
+                      /*path*/   Type.path,
+                      /*buf*/    Type.stat.out_ptr
+                     );
+         declareLazyFFI(SysFile,  "fstat", libc, "__fstat"+v, ctypes.default_abi,
+                      /*return*/ Type.negativeone_or_nothing,
+                      /*fd*/     Type.fd,
+                      /*buf*/    Type.stat.out_ptr
+                     );
        } else {
          // Mac OS X 32-bits, other Unix
          declareLazyFFI(SysFile,  "stat", libc, "stat", ctypes.default_abi,
