$NetBSD: patch-IkiWiki_Plugin_teximg.pm,v 1.1 2015/06/15 01:49:50 schmonz Exp $

Squelch Perl 5.22 regex deprecation warning.

--- IkiWiki/Plugin/teximg.pm.orig	2014-09-12 20:23:58.000000000 +0000
+++ IkiWiki/Plugin/teximg.pm
@@ -146,8 +146,8 @@ sub gen_image ($$$$) {
 	my $tex = $config{teximg_prefix};
 	$tex .= '\['.$code.'\]';
 	$tex .= $config{teximg_postfix};
-	$tex =~ s!\\documentclass{article}!\\documentclass[${height}pt]{article}!g;
-	$tex =~ s!\\documentclass{scrartcl}!\\documentclass[${height}pt]{scrartcl}!g;
+	$tex =~ s!\\documentclass\{article}!\\documentclass[${height}pt]{article}!g;
+	$tex =~ s!\\documentclass\{scrartcl}!\\documentclass[${height}pt]{scrartcl}!g;
 
 	my $tmp = eval { create_tmp_dir($digest) };
 	if (! $@ &&
