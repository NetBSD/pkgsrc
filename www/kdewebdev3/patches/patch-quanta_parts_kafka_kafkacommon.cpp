$NetBSD: patch-quanta_parts_kafka_kafkacommon.cpp,v 1.1 2013/01/17 16:04:49 joerg Exp $

--- quanta/parts/kafka/kafkacommon.cpp.orig	2013-01-17 13:00:59.000000000 +0000
+++ quanta/parts/kafka/kafkacommon.cpp
@@ -742,15 +742,15 @@ void kafkaCommon::fitsNodesPosition(Node
         {
             if(node->tag->getAttribute(j).nameLine == SNbeginLine)
             {
-                node->tag->getAttribute(j).nameLine += lineMovement;
-                node->tag->getAttribute(j).nameCol += colMovement;
-                node->tag->getAttribute(j).valueLine += lineMovement;
-                node->tag->getAttribute(j).valueCol += colMovement;
+                node->tag->getAttributeWriteable(j).nameLine += lineMovement;
+                node->tag->getAttributeWriteable(j).nameCol += colMovement;
+                node->tag->getAttributeWriteable(j).valueLine += lineMovement;
+                node->tag->getAttributeWriteable(j).valueCol += colMovement;
             }
             else
             {
-                node->tag->getAttribute(j).nameLine += lineMovement;
-                node->tag->getAttribute(j).valueLine += lineMovement;
+                node->tag->getAttributeWriteable(j).nameLine += lineMovement;
+                node->tag->getAttributeWriteable(j).valueLine += lineMovement;
             }
         }
         node = getNextNode(node, b);
