$NetBSD: patch-toolkit_components_osfile_osfile__unix__allthreads.jsm,v 1.1 2013/11/03 04:52:00 ryoon Exp $

--- toolkit/components/osfile/osfile_unix_allthreads.jsm.orig	2013-09-10 03:43:54.000000000 +0000
+++ toolkit/components/osfile/osfile_unix_allthreads.jsm
@@ -40,7 +40,7 @@ if (typeof Components != "undefined") {
   // Open libc
   let libc;
   let libc_candidates =  [ "libSystem.B.dylib",
-                           "libc.so.6",
+                           "libc.so.7",
                            "libc.so" ];
   for (let i = 0; i < libc_candidates.length; ++i) {
     try {
