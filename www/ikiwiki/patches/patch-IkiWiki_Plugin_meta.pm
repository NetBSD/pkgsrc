$NetBSD: patch-IkiWiki_Plugin_meta.pm,v 1.1 2015/08/30 03:07:03 schmonz Exp $

Fix [[!meta name=foo]] by closing the open quote.

--- IkiWiki/Plugin/meta.pm.orig	2014-09-12 20:23:58.000000000 +0000
+++ IkiWiki/Plugin/meta.pm
@@ -294,6 +294,7 @@ sub preprocess (@) {
 	elsif ($key eq 'name') {
 		push @{$metaheaders{$page}}, scrub('<meta name="'.
 			encode_entities($value).
+			'" '.
 			join(' ', map { "$_=\"$params{$_}\"" } keys %params).
 			' />', $page, $destpage);
 	}
