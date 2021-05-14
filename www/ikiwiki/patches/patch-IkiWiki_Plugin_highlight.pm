$NetBSD: patch-IkiWiki_Plugin_highlight.pm,v 1.3 2021/05/14 06:50:16 schmonz Exp $

Apply upstream patch 9ea3f9d to catch up to highlight 4.0 API change.

--- IkiWiki/Plugin/highlight.pm.orig	2020-02-02 20:23:50.000000000 +0000
+++ IkiWiki/Plugin/highlight.pm
@@ -54,7 +54,13 @@ sub checkconfig () {
 	eval q{use highlight};
 	if (highlight::DataDir->can('new')) {
 		$data_dir=new highlight::DataDir();
-		$data_dir->searchDataDir("");
+		if ( $data_dir->can('initSearchDirectories') ) {
+			# 4.0+
+			$data_dir -> initSearchDirectories("");
+		} else {
+			# pre-4.0
+			$data_dir -> searchDataDir("");
+		}
 	} else {
 		$data_dir=undef;
 	}
