$NetBSD: patch-IkiWiki.pm,v 1.1 2014/08/23 13:02:37 schmonz Exp $

Squelch commit warning with wiki.n.o's unusual (scheme-less) $config{url}.

--- IkiWiki.pm.orig	2014-07-02 19:45:57.000000000 +0000
+++ IkiWiki.pm
@@ -607,7 +607,8 @@ sub checkconfig () {
 
 			$local_cgiurl = $cgiurl->path;
 
-			if ($cgiurl->scheme ne $baseurl->scheme or
+			if (!defined $baseurl->scheme or
+				$cgiurl->scheme ne $baseurl->scheme or
 				$cgiurl->authority ne $baseurl->authority) {
 				# too far apart, fall back to absolute URLs
 				$local_url = "$config{url}/";
