$NetBSD: patch-vendor_x11-dl_src_link.rs,v 1.1 2021/06/20 08:51:19 tnn Exp $

Work around XIM error on NetBSD with native X11.
https://mail-index.netbsd.org/tech-x11/2021/06/20/msg002210.html

--- ../vendor/x11-dl-2.18.5/src/link.rs.orig	2020-01-26 08:06:45.000000000 +0000
+++ ../vendor/x11-dl-2.18.5/src/link.rs
@@ -87,7 +87,7 @@ impl DynamicLibrary {
         },
       };
 
-      let handle = libc::dlopen(cname.as_ptr(), libc::RTLD_LAZY);
+      let handle = libc::dlopen(cname.as_ptr(), libc::RTLD_LAZY | libc::RTLD_GLOBAL);
 
       if handle.is_null() {
         let msg = libc::dlerror();
