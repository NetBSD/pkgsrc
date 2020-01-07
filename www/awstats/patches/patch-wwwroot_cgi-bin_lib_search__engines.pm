$NetBSD: patch-wwwroot_cgi-bin_lib_search__engines.pm,v 1.1 2020/01/07 18:21:02 adam Exp $

Fix ampersand encoding that breaks XHTML output, ID 1824230.

--- wwwroot/cgi-bin/lib/search_engines.pm.orig	2017-02-20 23:35:50.000000000 +0000
+++ wwwroot/cgi-bin/lib/search_engines.pm
@@ -5084,7 +5084,7 @@
 'atlanticbb','atlanticbb',
 'atlas','Atlas.cz',
 'atomz','Atomz',
-'att','<a href="http://www.att.net/" title="Search Engine Home Page [new window]" rel="nofollow noopener noreferrer" target="_blank">AT&T search (powered by Google)</a>',
+'att','<a href="http://www.att.net/" title="Search Engine Home Page [new window]" rel="nofollow noopener noreferrer" target="_blank">AT&amp;T search (powered by Google)</a>',
 'auone','auone',
 'avantfind','<a href="http://www.avantfind.com/" title="Search Engine Home Page [new window]" rel="nofollow noopener noreferrer" target="_blank">Avantfind</a>',
 'avg','avg',
