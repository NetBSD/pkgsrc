$NetBSD: patch-IkiWiki_Plugin_mdwn.pm,v 1.1 2018/03/09 16:12:50 schmonz Exp $

Automatically detect which libdiscount flags to use.

--- IkiWiki/Plugin/mdwn.pm.orig	2018-02-28 10:41:06.000000000 +0000
+++ IkiWiki/Plugin/mdwn.pm
@@ -89,6 +89,55 @@ sub htmlize (@) {
 		    (! exists $config{nodiscount} || ! $config{nodiscount})) {
 			eval q{use Text::Markdown::Discount};
 			if (! $@) {
+				my $markdown = \&Text::Markdown::Discount::markdown;
+				my $always_flags = 0;
+
+				# Disable Pandoc-style % Title, % Author, % Date
+				# Use the meta plugin instead
+				$always_flags |= Text::Markdown::Discount::MKD_NOHEADER();
+
+				# Disable Unicodification of quote marks, em dashes...
+				# Use the typography plugin instead
+				$always_flags |= Text::Markdown::Discount::MKD_NOPANTS();
+
+				# Workaround for discount's eliding of <style> blocks.
+				# https://rt.cpan.org/Ticket/Display.html?id=74016
+				if (Text::Markdown::Discount->can('MKD_NOSTYLE')) {
+					$always_flags |= Text::Markdown::Discount::MKD_NOSTYLE();
+				}
+				elsif ($markdown->('<style>x</style>', 0) !~ '<style>' &&
+					$markdown->('<style>x</style>', 0x00400000) =~ m{<style>x</style>}) {
+					$always_flags |= 0x00400000;
+				}
+
+				# Enable fenced code blocks in libmarkdown >= 2.2.0
+				# https://bugs.debian.org/888055
+				if (Text::Markdown::Discount->can('MKD_FENCEDCODE')) {
+					$always_flags |= Text::Markdown::Discount::MKD_FENCEDCODE();
+				}
+				elsif ($markdown->("~~~\nx\n~~~", 0) !~ m{<pre\b} &&
+					$markdown->("~~~\nx\n~~~", 0x02000000) =~ m{<pre\b}) {
+					$always_flags |= 0x02000000;
+				}
+
+				# PHP Markdown Extra-style term\n: definition -> <dl>
+				if (Text::Markdown::Discount->can('MKD_DLEXTRA')) {
+					$always_flags |= Text::Markdown::Discount::MKD_DLEXTRA();
+				}
+				elsif ($markdown->("term\n: def\n", 0) !~ m{<dl>} &&
+					$markdown->("term\n: def\n", 0x01000000) =~ m{<dl>}) {
+					$always_flags |= 0x01000000;
+				}
+
+				# Allow dashes and underscores in tag names
+				if (Text::Markdown::Discount->can('MKD_GITHUBTAGS')) {
+					$always_flags |= Text::Markdown::Discount::MKD_GITHUBTAGS();
+				}
+				elsif ($markdown->('<foo_bar>', 0) !~ m{<foo_bar} &&
+					$markdown->('<foo_bar>', 0x08000000) =~ m{<foo_bar\b}) {
+					$always_flags |= 0x08000000;
+				}
+
 				$markdown_sub=sub {
 					my $t=shift;
 
@@ -96,15 +145,7 @@ sub htmlize (@) {
 					# https://rt.cpan.org/Ticket/Display.html?id=73657
 					return "" if $t=~/^\s*$/;
 
-					my $flags=0;
-
-					# Disable Pandoc-style % Title, % Author, % Date
-					# Use the meta plugin instead
-					$flags |= Text::Markdown::Discount::MKD_NOHEADER();
-
-					# Disable Unicodification of quote marks, em dashes...
-					# Use the typography plugin instead
-					$flags |= Text::Markdown::Discount::MKD_NOPANTS();
+					my $flags=$always_flags;
 
 					if ($config{mdwn_footnotes}) {
 						$flags |= Text::Markdown::Discount::MKD_EXTRA_FOOTNOTE();
@@ -114,42 +155,6 @@ sub htmlize (@) {
 						$flags |= Text::Markdown::Discount::MKD_NOALPHALIST();
 					}
 
-					# Workaround for discount's eliding
-					# of <style> blocks.
-					# https://rt.cpan.org/Ticket/Display.html?id=74016
-					if (Text::Markdown::Discount->can("MKD_NOSTYLE")) {
-						$flags |= Text::Markdown::Discount::MKD_NOSTYLE();
-					}
-					else {
-						# This is correct for the libmarkdown.so.2 ABI
-						$flags |= 0x00400000;
-					}
-
-					# Enable fenced code blocks in libmarkdown >= 2.2.0
-					# https://bugs.debian.org/888055
-					if (Text::Markdown::Discount->can("MKD_FENCEDCODE")) {
-						$flags |= Text::Markdown::Discount::MKD_FENCEDCODE();
-					}
-					else {
-						$flags |= 0x02000000;
-					}
-
-					# PHP Markdown Extra-style term\n: definition -> <dl>
-					if (Text::Markdown::Discount->can("MKD_DLEXTRA")) {
-						$flags |= Text::Markdown::Discount::MKD_DLEXTRA();
-					}
-					else {
-						$flags |= 0x01000000;
-					}
-
-					# Allow dashes and underscores in tag names
-					if (Text::Markdown::Discount->can("MKD_GITHUBTAGS")) {
-						$flags |= Text::Markdown::Discount::MKD_GITHUBTAGS();
-					}
-					else {
-						$flags |= 0x08000000;
-					}
-
 					return Text::Markdown::Discount::markdown($t, $flags);
 				}
 			}
