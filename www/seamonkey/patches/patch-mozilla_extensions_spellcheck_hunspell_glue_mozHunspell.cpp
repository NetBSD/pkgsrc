$NetBSD: patch-mozilla_extensions_spellcheck_hunspell_glue_mozHunspell.cpp,v 1.1 2016/03/30 12:56:53 ryoon Exp $

--- mozilla/extensions/spellcheck/hunspell/glue/mozHunspell.cpp.orig	2016-01-19 02:49:21.000000000 +0000
+++ mozilla/extensions/spellcheck/hunspell/glue/mozHunspell.cpp
@@ -392,6 +392,14 @@ mozHunspell::LoadDictionaryList(bool aNo
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
