$NetBSD: patch-lib_LWP_Protocol_https.pm,v 1.1.2.2 2014/05/28 19:45:34 tron Exp $

Fix for CVE-2014-3230 from
https://github.com/libwww-perl/lwp-protocol-https/pull/14

--- lib/LWP/Protocol/https.pm.orig	2013-04-29 21:16:18.000000000 +0000
+++ lib/LWP/Protocol/https.pm
@@ -20,7 +20,11 @@ sub _extra_sock_opts
 	$ssl_opts{SSL_verifycn_scheme} = 'www';
     }
     else {
-	$ssl_opts{SSL_verify_mode} = 0;
+	if ( $Net::HTTPS::SSL_SOCKET_CLASS eq 'Net::SSL' ) {
+	    $ssl_opts{SSL_verifycn_scheme} = '';
+	} else {
+	    $ssl_opts{SSL_verifycn_scheme} = 'none';
+	}
     }
     if ($ssl_opts{SSL_verify_mode}) {
 	unless (exists $ssl_opts{SSL_ca_file} || exists $ssl_opts{SSL_ca_path}) {
