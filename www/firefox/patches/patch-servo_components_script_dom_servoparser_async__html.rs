$NetBSD: patch-servo_components_script_dom_servoparser_async__html.rs,v 1.1 2017/11/03 22:07:27 ryoon Exp $

--- servo/components/script/dom/servoparser/async_html.rs.orig	2017-09-14 20:15:56.000000000 +0000
+++ servo/components/script/dom/servoparser/async_html.rs
@@ -568,7 +568,7 @@ impl TreeSink for Sink {
         }
         let node = self.new_parse_node();
         {
-            let mut data = self.get_parse_node_data_mut(&target.id);
+            let data = self.get_parse_node_data_mut(&target.id);
             data.contents = Some(node.clone());
         }
         self.send_op(ParseOperation::GetTemplateContents { target: target.id, contents: node.id });
@@ -596,7 +596,7 @@ impl TreeSink for Sink {
         let mut node = self.new_parse_node();
         node.qual_name = Some(name.clone());
         {
-            let mut node_data = self.get_parse_node_data_mut(&node.id);
+            let node_data = self.get_parse_node_data_mut(&node.id);
             node_data.is_integration_point = html_attrs.iter()
             .any(|attr| {
                 let attr_value = &String::from(attr.value.clone());
