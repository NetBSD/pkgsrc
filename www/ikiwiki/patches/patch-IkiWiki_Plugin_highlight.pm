$NetBSD: patch-IkiWiki_Plugin_highlight.pm,v 1.1 2019/05/27 03:53:31 schmonz Exp $

Catch up to highlight 3.51 API change.
From upstream git 4d06df9583e6c4145f8c6fc2fd51d7894c0b85ce

--- IkiWiki/Plugin/highlight.pm.orig	2019-02-26 23:01:54.000000000 +0000
+++ IkiWiki/Plugin/highlight.pm
@@ -62,10 +62,10 @@ sub checkconfig () {
 	if (! exists $config{filetypes_conf}) {
 	  if (! $data_dir ) {
 		$config{filetypes_conf}= "/etc/highlight/filetypes.conf";
-	      } elsif ( $data_dir -> can('searchFile') ) {
-		# 3.18 +
+	      } elsif ( $data_dir -> can('getFiletypesConfPath') ) {
+		# 3.14 +
 		$config{filetypes_conf}=
-		  $data_dir -> searchFile("filetypes.conf");
+		  $data_dir -> getFiletypesConfPath("filetypes");
 	      } else {
 		# 3.9 +
 		$config{filetypes_conf}=
