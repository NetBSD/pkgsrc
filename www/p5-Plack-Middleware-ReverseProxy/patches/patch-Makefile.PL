$NetBSD: patch-Makefile.PL,v 1.1 2017/06/07 14:51:18 ryoon Exp $

* Fix build with Perl 5.26.0

--- Makefile.PL.orig	2013-01-07 23:58:57.000000000 +0000
+++ Makefile.PL
@@ -1,3 +1,5 @@
+use FindBin;
+use lib $FindBin::Bin;
 use inc::Module::Install;
 name 'Plack-Middleware-ReverseProxy';
 all_from 'lib/Plack/Middleware/ReverseProxy.pm';
