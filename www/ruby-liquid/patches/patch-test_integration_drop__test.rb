$NetBSD: patch-test_integration_drop__test.rb,v 1.1 2024/01/21 09:07:55 taca Exp $

Remove support for taint checking.

--- test/integration/drop_test.rb.orig	2024-01-15 06:05:42.710512832 +0000
+++ test/integration/drop_test.rb
@@ -47,10 +47,6 @@ class ProductDrop < Liquid::Drop
     ContextDrop.new
   end
 
-  def user_input
-    "foo".taint
-  end
-
   protected
 
   def callmenot
@@ -112,32 +108,6 @@ class DropsTest < Minitest::Test
     assert_equal '  ', tpl.render!('product' => ProductDrop.new)
   end
 
-  def test_rendering_raises_on_tainted_attr
-    with_taint_mode(:error) do
-      tpl = Liquid::Template.parse('{{ product.user_input }}')
-      assert_raises TaintedError do
-        tpl.render!('product' => ProductDrop.new)
-      end
-    end
-  end
-
-  def test_rendering_warns_on_tainted_attr
-    with_taint_mode(:warn) do
-      tpl = Liquid::Template.parse('{{ product.user_input }}')
-      context = Context.new('product' => ProductDrop.new)
-      tpl.render!(context)
-      assert_equal [Liquid::TaintedError], context.warnings.map(&:class)
-      assert_equal "variable 'product.user_input' is tainted and was not escaped", context.warnings.first.to_s(false)
-    end
-  end
-
-  def test_rendering_doesnt_raise_on_escaped_tainted_attr
-    with_taint_mode(:error) do
-      tpl = Liquid::Template.parse('{{ product.user_input | escape }}')
-      tpl.render!('product' => ProductDrop.new)
-    end
-  end
-
   def test_drop_does_only_respond_to_whitelisted_methods
     assert_equal "", Liquid::Template.parse("{{ product.inspect }}").render!('product' => ProductDrop.new)
     assert_equal "", Liquid::Template.parse("{{ product.pretty_inspect }}").render!('product' => ProductDrop.new)
