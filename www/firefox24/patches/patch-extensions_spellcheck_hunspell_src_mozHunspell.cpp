$NetBSD: patch-extensions_spellcheck_hunspell_src_mozHunspell.cpp,v 1.1 2013/11/03 04:51:59 ryoon Exp $

--- extensions/spellcheck/hunspell/src/mozHunspell.cpp.orig	2013-09-10 03:43:29.000000000 +0000
+++ extensions/spellcheck/hunspell/src/mozHunspell.cpp
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
