$NetBSD: patch-Makefile.PL,v 1.1 2017/06/08 14:56:35 schmonz Exp $

Fix build with Perl 5.26.0.

--- Makefile.PL.orig	2005-12-26 16:17:54.000000000 +0000
+++ Makefile.PL
@@ -1,4 +1,5 @@
 use strict;
+BEGIN { push @INC, '.'; }
 use inc::Module::Install;
 
 name            'LWP-Authen-Wsse';
