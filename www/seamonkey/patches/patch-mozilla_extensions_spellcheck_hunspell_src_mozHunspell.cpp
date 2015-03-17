$NetBSD: patch-mozilla_extensions_spellcheck_hunspell_src_mozHunspell.cpp,v 1.3 2015/03/17 19:50:42 ryoon Exp $

--- mozilla/extensions/spellcheck/hunspell/src/mozHunspell.cpp.orig	2015-03-09 05:35:11.000000000 +0000
+++ mozilla/extensions/spellcheck/hunspell/src/mozHunspell.cpp
@@ -400,6 +400,12 @@ mozHunspell::LoadDictionaryList(bool aNo
     }
   }
 
+  // load system hunspell dictionaries
+  nsIFile* hunDir;
+  NS_NewNativeLocalFile(NS_LITERAL_CSTRING("@PREFIX@/share/hunspell"),
+                        true, &hunDir);
+  LoadDictionariesFromDir(hunDir);
+
   // find dictionaries from extensions requiring restart
   nsCOMPtr<nsISimpleEnumerator> dictDirs;
   rv = dirSvc->Get(DICTIONARY_SEARCH_DIRECTORY_LIST,
