$NetBSD: patch-src_FOptionContainer.hpp,v 1.1 2015/09/03 11:55:40 sborrill Exp $

maxuploadsize is a filtergroup settings

--- /usr/obj/pkgsrc/www/dansguardian/work.builder7/dansguardian-2.12.0.3/src/FOptionContainer.hpp.orig	2015-09-03 12:20:34.000000000 +0100
+++ /usr/obj/pkgsrc/www/dansguardian/work.builder7/dansguardian-2.12.0.3/src/FOptionContainer.hpp	2015-09-03 12:20:46.000000000 +0100
@@ -36,6 +36,7 @@
 	int weighted_phrase_mode;
 	int group_mode;
 	int embedded_url_weight;
+	int max_upload_size;
 	int naughtyness_limit;
 	int searchterm_limit;
 	bool createlistcachefiles;
