$NetBSD: patch-lib_LWPx_ParanoidAgent.pm,v 1.1 2014/09/17 22:46:17 schmonz Exp $

From upstream git commit 815c691, allow PERL_NET_HTTPS_SSL_SOCKET_CLASS
to control which SSL module gets used, rather than forcibly using
Net::SSL (which doesn't verify hostnames) no matter how the environment
variable is set.

--- lib/LWPx/ParanoidAgent.pm.orig	2013-11-11 15:45:04.000000000 +0000
+++ lib/LWPx/ParanoidAgent.pm
@@ -12,10 +12,6 @@ use HTTP::Status ();
 use strict;
 use Net::DNS;
 use LWP::Debug ();
-require Net::SSL;
-
-# fixes https://github.com/csirtgadgets/LWPx-ParanoidAgent/issues/4
-$Net::HTTPS::SSL_SOCKET_CLASS = 'Net::SSL';
 
 sub new {
     my $class = shift;
