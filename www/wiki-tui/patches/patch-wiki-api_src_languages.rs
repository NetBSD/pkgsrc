$NetBSD: patch-wiki-api_src_languages.rs,v 1.1 2024/12/05 07:02:09 pin Exp $

Allow finding languages.json
See, https://github.com/Builditluc/wiki-tui/issues/236

--- wiki-api/src/languages.rs.orig	2024-12-05 04:54:55.126975320 +0000
+++ wiki-api/src/languages.rs
@@ -1,3 +1,3 @@
 use wiki_api_macros::parse_languages;
 
-parse_languages!("./data/languages.json");
+parse_languages!("wiki-api/data/languages.json");
