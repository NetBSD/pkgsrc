$NetBSD: patch-t_inline.t,v 1.1 2015/06/15 01:49:50 schmonz Exp $

Squelch Perl 5.22 regex deprecation warning.

--- t/inline.t.orig	2015-06-14 15:12:56.000000000 +0000
+++ t/inline.t
@@ -52,7 +52,7 @@ $blob = readfile("t/tmp/out/friends.html
 like($blob, qr{\Q$add_new_post\E}, 'postform=yes forces postform');
 like($blob, qr{<input type="hidden" name="from" value="friends"},
 	'implicit rootpage is /friends');
-like($blob, qr[this page is {friends/garrus}.*this page is {friends/liara}]s,
+like($blob, qr[this page is \{friends/garrus}.*this page is \{friends/liara}]s,
 	'first two pages in desired sort order are present');
 unlike($blob, qr{friends/(?:midna|telma)},
 	'pages excluded by show should not be present');
@@ -62,7 +62,7 @@ unlike($blob, qr{\Q$add_new_post\E}, 'de
 
 $blob = readfile("t/tmp/out/enemies.html");
 unlike($blob, qr{\Q$add_new_post\E}, 'postform=no forces no postform');
-like($blob, qr[this page is {enemies/zant}.*this page is {enemies/rachni}]s,
+like($blob, qr[this page is \{enemies/zant}.*this page is \{enemies/rachni}]s,
 	'first two pages in reversed sort order are present');
 unlike($blob, qr{enemies/(?:benezia|geth)},
 	'pages excluded by show should not be present');
