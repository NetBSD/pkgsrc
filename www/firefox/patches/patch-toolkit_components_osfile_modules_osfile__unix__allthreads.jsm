$NetBSD: patch-toolkit_components_osfile_modules_osfile__unix__allthreads.jsm,v 1.2 2014/04/30 15:07:18 ryoon Exp $

--- toolkit/components/osfile/modules/osfile_unix_allthreads.jsm.orig	2014-04-18 02:04:23.000000000 +0000
+++ toolkit/components/osfile/modules/osfile_unix_allthreads.jsm
@@ -41,6 +41,8 @@ let Const = SharedAll.Constants.libc;
 // Open libc
 let libc;
 let libc_candidates =  [ "libc.so",
+                         "libc.so.6",
+                         "libc.so.7",
                          "libSystem.B.dylib",
                          "a.out" ];
 for (let i = 0; i < libc_candidates.length; ++i) {
