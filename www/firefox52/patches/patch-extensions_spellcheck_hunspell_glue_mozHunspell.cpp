$NetBSD: patch-extensions_spellcheck_hunspell_glue_mozHunspell.cpp,v 1.1 2017/04/27 01:55:57 ryoon Exp $

* Read pkgsrc hunspell dictionaries

--- extensions/spellcheck/hunspell/glue/mozHunspell.cpp.orig	2017-01-23 16:13:57.000000000 +0000
+++ extensions/spellcheck/hunspell/glue/mozHunspell.cpp
@@ -381,6 +381,14 @@ mozHunspell::LoadDictionaryList(bool aNo
     }
   }
 
+  // load system hunspell dictionaries
+  nsCOMPtr<nsIFile> hunDir;
+  NS_NewNativeLocalFile(NS_LITERAL_CSTRING("%%LOCALBASE%%/share/hunspell"),
+                        true, getter_AddRefs(hunDir));
+  if (hunDir) {
+      LoadDictionariesFromDir(hunDir);
+  }
+
   // find dictionaries from extensions requiring restart
   nsCOMPtr<nsISimpleEnumerator> dictDirs;
   rv = dirSvc->Get(DICTIONARY_SEARCH_DIRECTORY_LIST,
