$NetBSD: patch-IkiWiki_Plugin_highlight.pm,v 1.4 2021/11/02 09:44:48 schmonz Exp $

Apply upstream patch 9ea3f9d to catch up to highlight 4.0 API change.
Use pkgsrc paths.

--- IkiWiki/Plugin/highlight.pm.orig	2020-02-02 20:23:50.000000000 +0000
+++ IkiWiki/Plugin/highlight.pm
@@ -36,14 +36,14 @@ sub getsetup () {
 		},
 		filetypes_conf => {
 			type => "string",
-			example => "/etc/highlight/filetypes.conf",
+			example => "@PKG_SYSCONFBASEDIR@/highlight/filetypes.conf",
 			description => "location of highlight's filetypes.conf",
 			safe => 0,
 			rebuild => undef,
 		},
 		langdefdir => {
 			type => "string",
-			example => "/usr/share/highlight/langDefs",
+			example => "@PREFIX@/share/highlight/langDefs",
 			description => "location of highlight's langDefs directory",
 			safe => 0,
 			rebuild => undef,
@@ -54,14 +54,20 @@ sub checkconfig () {
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
 
 	if (! exists $config{filetypes_conf}) {
 	  if (! $data_dir ) {
-		$config{filetypes_conf}= "/etc/highlight/filetypes.conf";
+		$config{filetypes_conf}= "@PKG_SYSCONFBASEDIR@/highlight/filetypes.conf";
 	      } elsif ( $data_dir -> can('getFiletypesConfPath') ) {
 		# 3.14 +
 		$config{filetypes_conf}=
@@ -75,7 +81,7 @@ sub checkconfig () {
 	# note that this is only used for old versions of highlight
 	# where $data_dir will not be defined.
 	if (! exists $config{langdefdir}) {
-		$config{langdefdir}= "/usr/share/highlight/langDefs";
+		$config{langdefdir}= "@PREFIX@/share/highlight/langDefs";
 
 	}
 	if (exists $config{tohighlight} && read_filetypes()) {
