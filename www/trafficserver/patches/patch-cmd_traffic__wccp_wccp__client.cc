$NetBSD: patch-cmd_traffic__wccp_wccp__client.cc,v 1.1 2017/08/17 14:57:09 fhajny Exp $

Use getopt_long for better portability, same as the rest of the code.

--- cmd/traffic_wccp/wccp_client.cc.orig	2017-07-18 06:25:04.000000000 +0000
+++ cmd/traffic_wccp/wccp_client.cc
@@ -141,7 +141,7 @@ main(int argc, char **argv)
   bool fail            = false;
   const char *FAIL_MSG = "";
 
-  while (-1 != (zret = getopt_long_only(argc, argv, "", OPTIONS, &zidx))) {
+  while (-1 != (zret = getopt_long(argc, argv, "", OPTIONS, &zidx))) {
     switch (zret) {
     case OPT_HELP:
       FAIL_MSG = "Usage:";
