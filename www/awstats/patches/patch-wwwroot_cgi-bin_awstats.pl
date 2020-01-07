$NetBSD: patch-wwwroot_cgi-bin_awstats.pl,v 1.1 2020/01/07 18:21:02 adam Exp $

Check for configdir.

--- wwwroot/cgi-bin/awstats.pl.orig	2018-01-07 14:36:46.000000000 +0000
+++ wwwroot/cgi-bin/awstats.pl
@@ -1723,7 +1723,7 @@ sub Read_Config {
 			"/etc/opt/awstats"
 		); 
 
-	if ($configdir) {
+	if ($configdir && $ENV{"AWSTATS_ENABLE_CONFIG_DIR"}) {
 		# Check if configdir is outside default values.
 		my $outsidedefaultvalue=1;
 		foreach (@PossibleConfigDir) {
