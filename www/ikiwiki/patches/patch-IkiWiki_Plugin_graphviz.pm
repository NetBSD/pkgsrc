$NetBSD: patch-IkiWiki_Plugin_graphviz.pm,v 1.1 2018/10/22 04:33:25 schmonz Exp $

Add upstream patch to give graph an optional "file" param, like table's.

--- IkiWiki/Plugin/graphviz.pm.orig	2018-03-11 15:54:34.000000000 +0000
+++ IkiWiki/Plugin/graphviz.pm
@@ -95,6 +95,14 @@ sub render_graph (\%) {
 sub graph (@) {
 	my %params=@_;
 
+	if (exists $params{file}) {
+		if (! exists $pagesources{$params{file}}) {
+			error gettext("cannot find file");
+		}
+		$params{src} = readfile(srcfile($params{file}));
+		add_depends($params{page}, $params{file});
+	}
+
 	# Support wikilinks in the graph source.
 	my $src=$params{src};
 	$src="" unless defined $src;
