$NetBSD: patch-extensions_spellcheck_hunspell_src_mozHunspell.cpp,v 1.9 2015/04/05 12:54:11 ryoon Exp $

Load system hunspell dictionaries.

--- extensions/spellcheck/hunspell/src/mozHunspell.cpp.orig	2015-03-27 02:20:32.000000000 +0000
+++ extensions/spellcheck/hunspell/src/mozHunspell.cpp
@@ -400,6 +400,14 @@ mozHunspell::LoadDictionaryList(bool aNo
     }
   }
 
+  // load system hunspell dictionaries
+  nsCOMPtr<nsIFile> hunDir;
+  NS_NewNativeLocalFile(NS_LITERAL_CSTRING("/usr/pkg/share/hunspell"),
+                        true, getter_AddRefs(hunDir));
+  if (hunDir) {
+      LoadDictionariesFromDir(hunDir);
+  }
+
   // find dictionaries from extensions requiring restart
   nsCOMPtr<nsISimpleEnumerator> dictDirs;
   rv = dirSvc->Get(DICTIONARY_SEARCH_DIRECTORY_LIST,
