$NetBSD: patch-Makefile.PL,v 1.1 2017/06/07 00:00:24 ryoon Exp $

* Fix build with Perl 5.26.0

--- Makefile.PL.orig	2013-10-22 11:12:47.000000000 +0000
+++ Makefile.PL
@@ -1,4 +1,6 @@
 use strict;
+use FindBin;
+use lib $FindBin::Bin;
 use inc::Module::Install;
 
 name           'HTTP-MultiPartParser';
