$NetBSD: patch-extensions_spellcheck_hunspell_src_mozHunspell.cpp,v 1.2 2014/02/08 09:36:00 ryoon Exp $

--- extensions/spellcheck/hunspell/src/mozHunspell.cpp.orig	2014-01-28 04:03:40.000000000 +0000
+++ extensions/spellcheck/hunspell/src/mozHunspell.cpp
@@ -426,6 +426,12 @@ mozHunspell::LoadDictionaryList()
     }
   }
 
+  // load system hunspell dictionaries
+  nsIFile* hunDir;
+  NS_NewNativeLocalFile(NS_LITERAL_CSTRING("/usr/pkg/share/hunspell"),
+			true, &hunDir);
+  LoadDictionariesFromDir(hunDir);
+
   // find dictionaries from extensions requiring restart
   nsCOMPtr<nsISimpleEnumerator> dictDirs;
   rv = dirSvc->Get(DICTIONARY_SEARCH_DIRECTORY_LIST,
