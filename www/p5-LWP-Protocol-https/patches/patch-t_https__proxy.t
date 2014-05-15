$NetBSD: patch-t_https__proxy.t,v 1.1 2014/05/15 10:17:38 wiz Exp $

Fix for CVE-2014-3230 from
https://github.com/libwww-perl/lwp-protocol-https/pull/14

--- t/https_proxy.t.orig	2014-04-18 16:21:26.000000000 +0000
+++ t/https_proxy.t
@@ -66,7 +66,10 @@ my %ua;
 $ua{noproxy} = LWP::UserAgent->new(
     keep_alive => 10, # size of connection cache
     # server does not know the expected name and returns generic certificate
-    ssl_opts => { verify_hostname => 0 }
+    ssl_opts => { 
+	verify_hostname => 0, 
+	SSL_ca_file => $cafile,
+    }
 );
 
 $ua{proxy} = LWP::UserAgent->new(
