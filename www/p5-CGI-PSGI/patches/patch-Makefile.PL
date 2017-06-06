$NetBSD: patch-Makefile.PL,v 1.1 2017/06/06 14:30:31 ryoon Exp $

* Fix build with Perl 5.26.0

--- Makefile.PL.orig	2010-11-10 07:38:05.000000000 +0000
+++ Makefile.PL
@@ -1,3 +1,5 @@
+use FindBin;
+use lib $FindBin::Bin;
 use inc::Module::Install;
 name 'CGI-PSGI';
 all_from 'lib/CGI/PSGI.pm';
