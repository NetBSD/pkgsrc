$NetBSD: patch-lib_wccp_wccp-test-router.cc,v 1.1 2017/08/17 14:57:09 fhajny Exp $

Use getopt_long for better portability, same as the rest of the code.

--- lib/wccp/wccp-test-router.cc.orig	2015-06-30 04:11:56.000000000 +0000
+++ lib/wccp/wccp-test-router.cc
@@ -81,7 +81,7 @@ main(int argc, char **argv)
   //  char const* text; // Scratch pointer for config access.
   char const *FAIL_MSG = "";
 
-  while (-1 != (zret = getopt_long_only(argc, argv, "", OPTIONS, &zidx))) {
+  while (-1 != (zret = getopt_long(argc, argv, "", OPTIONS, &zidx))) {
     switch (zret) {
     case OPT_HELP:
       FAIL_MSG = "Usage:";
