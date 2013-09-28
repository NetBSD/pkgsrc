$NetBSD: patch-mozilla_toolkit_components_osfile_osfile__unix__allthreads.jsm,v 1.1 2013/09/28 14:37:05 ryoon Exp $

--- mozilla/toolkit/components/osfile/osfile_unix_allthreads.jsm.orig	2013-09-16 18:26:58.000000000 +0000
+++ mozilla/toolkit/components/osfile/osfile_unix_allthreads.jsm
@@ -40,7 +40,7 @@ if (typeof Components != "undefined") {
   // Open libc
   let libc;
   let libc_candidates =  [ "libSystem.B.dylib",
-                           "libc.so.6",
+                           "libc.so.7",
                            "libc.so" ];
   for (let i = 0; i < libc_candidates.length; ++i) {
     try {
