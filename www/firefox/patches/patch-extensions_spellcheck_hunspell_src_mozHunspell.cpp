$NetBSD: patch-extensions_spellcheck_hunspell_src_mozHunspell.cpp,v 1.8 2015/02/28 04:30:55 ryoon Exp $

Load system hunspell dictionaries.

--- extensions/spellcheck/hunspell/src/mozHunspell.cpp.orig	2015-02-17 21:40:49.000000000 +0000
+++ extensions/spellcheck/hunspell/src/mozHunspell.cpp
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
