$NetBSD: patch-extensions_spellcheck_hunspell_glue_mozHunspell.cpp,v 1.3 2017/01/25 13:24:51 ryoon Exp $

* Read pkgsrc hunspell dictionaries

--- extensions/spellcheck/hunspell/glue/mozHunspell.cpp.orig	2017-01-16 16:16:49.000000000 +0000
+++ extensions/spellcheck/hunspell/glue/mozHunspell.cpp
@@ -358,6 +358,14 @@ mozHunspell::LoadDictionaryList(bool aNo
     }
   }
 
+  // load system hunspell dictionaries
+  nsCOMPtr<nsIFile> hunDir;
+  NS_NewNativeLocalFile(NS_LITERAL_CSTRING("@PREFIX@/share/hunspell"),
+                        true, getter_AddRefs(hunDir));
+  if (hunDir) {
+      LoadDictionariesFromDir(hunDir);
+  }
+
   // find dictionaries from extensions requiring restart
   nsCOMPtr<nsISimpleEnumerator> dictDirs;
   rv = dirSvc->Get(DICTIONARY_SEARCH_DIRECTORY_LIST,
