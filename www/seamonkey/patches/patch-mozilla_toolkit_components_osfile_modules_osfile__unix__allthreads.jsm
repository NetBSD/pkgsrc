$NetBSD: patch-mozilla_toolkit_components_osfile_modules_osfile__unix__allthreads.jsm,v 1.2 2014/06/22 08:54:39 ryoon Exp $

--- mozilla/toolkit/components/osfile/modules/osfile_unix_allthreads.jsm.orig	2014-06-13 00:46:12.000000000 +0000
+++ mozilla/toolkit/components/osfile/modules/osfile_unix_allthreads.jsm
@@ -41,6 +41,8 @@ let Const = SharedAll.Constants.libc;
 // Open libc
 let libc;
 let libc_candidates =  [ "libc.so",
+                         "libc.so.6",
+                         "libc.so.7",
                          "libSystem.B.dylib",
                          "a.out" ];
 for (let i = 0; i < libc_candidates.length; ++i) {
