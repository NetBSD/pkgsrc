$NetBSD: patch-toolkit_components_osfile_modules_osfile__unix__back.jsm,v 1.5 2014/03/20 21:02:00 ryoon Exp $

Based on martin@'s patch for firefox 27.0

* Use off_t for st_size
* Use function name for NetBSD

--- toolkit/components/osfile/modules/osfile_unix_back.jsm.orig	2014-03-15 05:19:36.000000000 +0000
+++ toolkit/components/osfile/modules/osfile_unix_back.jsm
@@ -558,18 +558,19 @@
            return Stat.fxstat(ver, fd, buf);
          };
        } else if (OS.Constants.Sys.Name == "NetBSD") {
-         // NetBSD 5.0 and newer
-         declareLazyFFI(SysFile,  "stat", libc, "__stat50", ctypes.default_abi,
+         // NetBSD 5.0 uses *30, and netbsd-6 uses *50
+         let v = OS.Constants.libc.OSFILE_SIZEOF_TIME_T < 8 ? "30" : "50";
+         declareLazyFFI(SysFile,  "stat", libc, "__stat"+v, ctypes.default_abi,
                       /*return*/ Type.negativeone_or_nothing,
                       /*path*/   Type.path,
                       /*buf*/    Type.stat.out_ptr
                      );
-         declareLazyFFI(SysFile,  "lstat", libc, "__lstat50", ctypes.default_abi,
+         declareLazyFFI(SysFile,  "lstat", libc, "__lstat"+v, ctypes.default_abi,
                       /*return*/ Type.negativeone_or_nothing,
                       /*path*/   Type.path,
                       /*buf*/    Type.stat.out_ptr
                      );
-         declareLazyFFI(SysFile,  "fstat", libc, "__fstat50", ctypes.default_abi,
+         declareLazyFFI(SysFile,  "fstat", libc, "__fstat"+v, ctypes.default_abi,
                       /*return*/ Type.negativeone_or_nothing,
                       /*fd*/     Type.fd,
                       /*buf*/    Type.stat.out_ptr
