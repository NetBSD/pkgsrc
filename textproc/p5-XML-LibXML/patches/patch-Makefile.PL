$NetBSD: patch-Makefile.PL,v 1.1 2014/06/10 22:38:48 joerg Exp $

Patch away broken mixup of linker vs compiler invocation and
hard-code the result.

--- Makefile.PL.orig	2014-06-10 22:31:37.000000000 +0000
+++ Makefile.PL
@@ -411,32 +411,7 @@ sub _libxml_check_lib {
     }
 }
 
-print "Checking for ability to link against xml2...";
-if ( _libxml_check_lib('xml2') ) {
-    print "yes\n";
-}
-else {
-    print "no\n";
-    print "Checking for ability to link against libxml2...";
-    if ( _libxml_check_lib('libxml2')) {
-        print "yes\n";
-    }
-    else {
-        print STDERR <<"DEATH";
-libxml2, zlib, and/or the Math library (-lm) have not been found.
-Try setting LIBS and INC values on the command line
-Or get libxml2 from
-  http://xmlsoft.org/
-If you install via RPMs, make sure you also install the -devel
-RPMs, as this is where the headers (.h files) are.
-
-Also, you may try to run perl Makefile.PL with the DEBUG=1 parameter
-to see the exact reason why the detection of libxml2 installation
-failed or why Makefile.PL was not able to compile a test program.
-DEATH
-        exit 0; # 0 recommended by http://cpantest.grango.org (Notes for CPAN Authors)
-    }
-}
+$config{LIBS} = "-lxml2";
 
 # -------------------------------------------------------------------------- #
 # _NOW_ write the Makefile
