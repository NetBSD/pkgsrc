$NetBSD: patch-IkiWiki_Plugin_polygen.pm,v 1.1 2021/11/02 09:44:48 schmonz Exp $

Use pkgsrc paths.

--- IkiWiki/Plugin/polygen.pm.orig	2020-02-02 20:23:50.000000000 +0000
+++ IkiWiki/Plugin/polygen.pm
@@ -38,8 +38,8 @@ sub preprocess (@) {
 	$symbol =~ s/[^A-Za-z0-9]//g if defined $symbol;
 	$symbol = IkiWiki::possibly_foolish_untaint($symbol) if defined $symbol;
 
-	my $grmfile = '/usr/share/polygen/ita/polygen.grm';
-	if (! -d '/usr/share/polygen') {
+	my $grmfile = '@PREFIX@/share/polygen/ita/polygen.grm';
+	if (! -d '@PREFIX@/share/polygen') {
 		error gettext("polygen not installed");
 	}
 	find({wanted => sub {
@@ -48,7 +48,7 @@ sub preprocess (@) {
 			}
 		},
 		no_chdir => 1,
-	}, '/usr/share/polygen');
+	}, '@PREFIX@/share/polygen');
 	
 	my $res;
 	if (defined $symbol) {
