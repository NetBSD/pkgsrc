$NetBSD: patch-extensions_spellcheck_hunspell_src_mozHunspell.cpp,v 1.5 2015/01/16 22:42:09 ryoon Exp $

--- extensions/spellcheck/hunspell/src/mozHunspell.cpp.orig	2015-01-09 04:38:27.000000000 +0000
+++ extensions/spellcheck/hunspell/src/mozHunspell.cpp
@@ -400,6 +400,12 @@ mozHunspell::LoadDictionaryList(bool aNo
     }
   }
 
+  // load system hunspell dictionaries
+  nsIFile* hunDir;
+  NS_NewNativeLocalFile(NS_LITERAL_CSTRING("%%LOCALBASE%%/share/hunspell"),
+			true, &hunDir);
+  LoadDictionariesFromDir(hunDir);
+
   // find dictionaries from extensions requiring restart
   nsCOMPtr<nsISimpleEnumerator> dictDirs;
   rv = dirSvc->Get(DICTIONARY_SEARCH_DIRECTORY_LIST,
