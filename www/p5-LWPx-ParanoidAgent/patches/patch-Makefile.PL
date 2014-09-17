$NetBSD: patch-Makefile.PL,v 1.1 2014/09/17 22:46:17 schmonz Exp $

From upstream git commit 815c691, allow PERL_NET_HTTPS_SSL_SOCKET_CLASS
to control which SSL module gets used, rather than forcibly using
Net::SSL (which doesn't verify hostnames) no matter how the environment
variable is set.

--- Makefile.PL.orig	2013-11-04 19:30:07.000000000 +0000
+++ Makefile.PL
@@ -6,7 +6,6 @@ WriteMakefile( 
         'LWP::UserAgent'    => 0,
         'Net::DNS'          => 0,
         'Time::HiRes'       => 0,
-        'Net::SSL'          => '2.85'
     },
     'META_MERGE'  => {
         "resources"   => {
