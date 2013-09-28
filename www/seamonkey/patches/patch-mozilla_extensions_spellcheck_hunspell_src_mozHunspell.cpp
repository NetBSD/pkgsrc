$NetBSD: patch-mozilla_extensions_spellcheck_hunspell_src_mozHunspell.cpp,v 1.1 2013/09/28 14:37:05 ryoon Exp $

--- mozilla/extensions/spellcheck/hunspell/src/mozHunspell.cpp.orig	2013-09-16 18:26:33.000000000 +0000
+++ mozilla/extensions/spellcheck/hunspell/src/mozHunspell.cpp
@@ -417,6 +417,12 @@ mozHunspell::LoadDictionaryList()
     }
   }
 
+  // load system hunspell dictionaries
+  nsIFile* hunDir;
+  NS_NewNativeLocalFile(NS_LITERAL_CSTRING("@PREFIX@/share/hunspell"),
+			true, &hunDir);
+  LoadDictionariesFromDir(hunDir);
+
   // find dictionaries from extensions requiring restart
   nsCOMPtr<nsISimpleEnumerator> dictDirs;
   rv = dirSvc->Get(DICTIONARY_SEARCH_DIRECTORY_LIST,
