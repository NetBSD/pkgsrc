$NetBSD: patch-lib_Locale_Po4a_Text.pm,v 1.1 2022/11/26 03:40:21 schmonz Exp $

Avoid needing additional dependency not yet in pkgsrc (or
still-experimental core feature).

--- lib/Locale/Po4a/Text.pm.orig	2022-09-04 14:32:26.000000000 +0000
+++ lib/Locale/Po4a/Text.pm
@@ -58,7 +58,6 @@ use vars qw(@ISA @EXPORT);
 use Locale::Po4a::TransTractor;
 use Locale::Po4a::Common;
 use YAML::Tiny;
-use Syntax::Keyword::Try;
 
 =head1 OPTIONS ACCEPTED BY THIS MODULE
 
@@ -602,11 +601,10 @@ sub parse_markdown_yaml_front_matter {
 
     my $yamlarray;    # the parsed YFM content
     my $yamlres;      # containing the parse error, if any
-    try {
+    eval q{
         $yamlarray = YAML::Tiny->read_string($yfm);
-    } catch {
-        $yamlres = $@;
-    }
+    };
+    $yamlres = $@ if $@;
 
     if ( defined($yamlres) ) {
         if ($yfm_lenient) {
