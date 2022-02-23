$NetBSD: patch-src_Web_Bower_PackageMeta_Internal.hs,v 1.1 2022/02/23 16:09:43 pho Exp $

Fix build with aeson-2.0

--- src/Web/Bower/PackageMeta/Internal.hs.orig	2016-12-25 00:06:09.000000000 +0000
+++ src/Web/Bower/PackageMeta/Internal.hs
@@ -29,6 +29,7 @@ import qualified Data.ByteString.Lazy as
 import Data.Aeson ((.=))
 import qualified Data.Aeson as A
 import qualified Data.Aeson.Types as Aeson
+import qualified Data.Aeson.Key as Key
 import Data.Aeson.BetterErrors (Parse, ParseError, asText, asString, asBool, eachInArray, eachInObjectWithKey, withText, key, keyMay, keyOrDefault, toAesonParser', toAesonParser, displayError, parse)
 
 ---------------------
@@ -222,7 +223,7 @@ asPackageMeta =
 
   asAssocListOf :: (Text -> a) -> Parse BowerError [(PackageName, a)]
   asAssocListOf g =
-    eachInObjectWithKey parsePackageName (g <$> asText)
+    eachInObjectWithKey (parsePackageName . Key.toText) (g <$> asText)
 
 parseModuleType :: Text -> Either BowerError ModuleType
 parseModuleType str =
@@ -301,8 +302,8 @@ instance A.ToJSON PackageMeta where
       ]
 
       where
-      assoc :: A.ToJSON a => Text -> [(PackageName, a)] -> [Aeson.Pair]
-      assoc = maybeArrayAssocPair runPackageName
+      assoc :: A.ToJSON a => Aeson.Key -> [(PackageName, a)] -> [Aeson.Pair]
+      assoc = maybeArrayAssocPair (Key.fromText . runPackageName)
 
 instance A.ToJSON PackageName where
   toJSON = A.toJSON . runPackageName
@@ -329,14 +330,14 @@ instance A.ToJSON Version where
 instance A.ToJSON VersionRange where
   toJSON = A.toJSON . runVersionRange
 
-maybePair :: A.ToJSON a => Text -> Maybe a -> [Aeson.Pair]
+maybePair :: A.ToJSON a => Aeson.Key -> Maybe a -> [Aeson.Pair]
 maybePair k = maybe [] (\val -> [k .= val])
 
-maybeArrayPair :: A.ToJSON a => Text -> [a] -> [Aeson.Pair]
+maybeArrayPair :: A.ToJSON a => Aeson.Key -> [a] -> [Aeson.Pair]
 maybeArrayPair _   [] = []
 maybeArrayPair k xs = [k .= xs]
 
-maybeArrayAssocPair :: A.ToJSON b => (a -> Text) -> Text -> [(a,b)] -> [Aeson.Pair]
+maybeArrayAssocPair :: A.ToJSON b => (a -> Aeson.Key) -> Aeson.Key -> [(a,b)] -> [Aeson.Pair]
 maybeArrayAssocPair _ _   [] = []
 maybeArrayAssocPair f k xs = [k .= A.object (map (\(k', v) -> f k' .= v) xs)]
 
