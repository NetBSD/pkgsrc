$NetBSD: patch-t_mdwn.t,v 1.1 2018/03/09 16:12:50 schmonz Exp $

Automatically detect which libdiscount flags to use.

--- t/mdwn.t.orig	2018-02-28 10:41:06.000000000 +0000
+++ t/mdwn.t
@@ -8,6 +8,7 @@ BEGIN { use_ok("IkiWiki"); }
 
 %config=IkiWiki::defaultconfig();
 $config{srcdir}=$config{destdir}="/dev/null";
+$config{disable_plugins}=["htmlscrubber"];
 IkiWiki::loadplugins();
 IkiWiki::checkconfig();
 
@@ -41,4 +42,25 @@ like(IkiWiki::htmlize("foo", "foo", "mdw
 	"This works[^1]\n\n[^1]: Sometimes it doesn't.\n"),
 	qr{<p>This works<sup\W}, "footnotes can be enabled");
 
+SKIP: {
+	skip 'set $IKIWIKI_TEST_ASSUME_MODERN_DISCOUNT if you have Discount 2.2.0+', 4
+		unless $ENV{IKIWIKI_TEST_ASSUME_MODERN_DISCOUNT};
+	like(IkiWiki::htmlize("foo", "foo", "mdwn",
+			"Definition list\n: A useful HTML structure\n"),
+		qr{<dl>.*<dt>Definition list</dt>\s*<dd>A useful HTML structure</dd>}s,
+		"definition lists are enabled by default");
+	like(IkiWiki::htmlize("foo", "foo", "mdwn",
+			"```\n#!/bin/sh\n```\n"),
+		qr{<pre>\s*<code>\s*[#]!/bin/sh\s*</code>\s*</pre>}s,
+		"code blocks are enabled by default");
+	like(IkiWiki::htmlize("foo", "foo", "mdwn",
+			"<foo_bar>"),
+		qr{<foo_bar>},
+		"GitHub tag name extensions are enabled by default");
+	like(IkiWiki::htmlize("foo", "foo", "mdwn",
+			"<style>foo</style>"),
+		qr{<style>foo</style>},
+		"Styles are not stripped by default");
+}
+
 done_testing();
