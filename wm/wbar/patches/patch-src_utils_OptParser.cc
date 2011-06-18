$NetBSD: patch-src_utils_OptParser.cc,v 1.1.1.1 2011/06/18 15:16:24 wiz Exp $

Use more portable getopt_long instead of getopt_long_only.
http://code.google.com/p/wbar/issues/detail?id=55

--- src/utils/OptParser.cc.orig	2011-05-08 20:11:22.000000000 +0000
+++ src/utils/OptParser.cc
@@ -48,7 +48,7 @@ bool OptParser::isSet(Options opt)
     {
         int option_index = 0;
 
-        c = getopt_long_only(argc, argv, "hcv", long_options, &option_index);
+        c = getopt_long(argc, argv, "hcv", long_options, &option_index);
         if (c == -1) break;
         if (option_index == (int)opt) return true;
         if (c == (int) HELP && opt == HELP) return true;
@@ -71,7 +71,7 @@ std::string OptParser::getArg(Options op
     {
         int option_index = 0;
 
-        c = getopt_long_only(argc, argv, "hcv", long_options, &option_index);
+        c = getopt_long(argc, argv, "hcv", long_options, &option_index);
         if (c == -1) break;
         if (!optarg) continue;
         if (option_index == (int)opt) return optarg;
