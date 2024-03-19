$NetBSD: patch-IkiWiki_Plugin_highlight.pm,v 1.5 2024/03/19 14:08:24 schmonz Exp $

Apply upstream patch 9ea3f9d to catch up to highlight 4.0 API change.
Use pkgsrc paths.

--- IkiWiki/Plugin/highlight.pm.orig	2024-03-18 16:42:55.000000000 +0000
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
@@ -67,7 +67,7 @@ sub checkconfig () {
 
 	if (! exists $config{filetypes_conf}) {
 	  if (! $data_dir ) {
-		$config{filetypes_conf}= "/etc/highlight/filetypes.conf";
+		$config{filetypes_conf}= "@PKG_SYSCONFBASEDIR@/highlight/filetypes.conf";
 	      } elsif ( $data_dir -> can('getFiletypesConfPath') ) {
 		# 3.14 +
 		$config{filetypes_conf}=
@@ -81,7 +81,7 @@ sub checkconfig () {
 	# note that this is only used for old versions of highlight
 	# where $data_dir will not be defined.
 	if (! exists $config{langdefdir}) {
-		$config{langdefdir}= "/usr/share/highlight/langDefs";
+		$config{langdefdir}= "@PREFIX@/share/highlight/langDefs";
 
 	}
 	if (exists $config{tohighlight} && read_filetypes()) {
