$NetBSD: patch-mozilla_toolkit_components_osfile_modules_osfile__unix__allthreads.jsm,v 1.1 2014/03/30 04:13:17 ryoon Exp $

--- mozilla/toolkit/components/osfile/modules/osfile_unix_allthreads.jsm.orig	2014-03-19 01:42:15.000000000 +0000
+++ mozilla/toolkit/components/osfile/modules/osfile_unix_allthreads.jsm
@@ -41,7 +41,7 @@ let Const = SharedAll.Constants.libc;
 // Open libc
 let libc;
 let libc_candidates =  [ "libSystem.B.dylib",
-                         "libc.so.6",
+                         "libc.so.7",
                          "libc.so" ];
 for (let i = 0; i < libc_candidates.length; ++i) {
   try {
