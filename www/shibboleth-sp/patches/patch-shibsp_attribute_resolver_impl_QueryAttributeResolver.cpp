--- shibsp/attribute/resolver/impl/QueryAttributeResolver.cpp.orig	2020-03-18 11:45:13.000000000 -0700
+++ shibsp/attribute/resolver/impl/QueryAttributeResolver.cpp	2020-07-07 12:26:37.773204823 -0700
@@ -266,7 +266,7 @@
                 }
             }
         }
-        catch (const exception& ex) {
+        catch (const std::exception& ex) {
             m_log.error("exception loading attribute designator: %s", ex.what());
         }
         child = XMLHelper::getNextSiblingElement(child);
@@ -342,7 +342,7 @@
             client.sendSAML(request, application.getId(), mcc, loc.get());
             response.reset(client.receiveSAML());
         }
-        catch (const exception& ex) {
+        catch (const std::exception& ex) {
             m_log.error("exception during SAML query to %s: %s", loc.get(), ex.what());
             soaper.reset();
         }
@@ -395,7 +395,7 @@
         if (!policy->isAuthenticated())
             throw SecurityPolicyException("Security of SAML 1.x query result not established.");
     }
-    catch (const exception& ex) {
+    catch (const std::exception& ex) {
         m_log.error("assertion failed policy validation: %s", ex.what());
         throw;
     }
@@ -437,7 +437,7 @@
             filter->filterAttributes(fc, ctx.getResolvedAttributes());
         }
     }
-    catch (const exception& ex) {
+    catch (const std::exception& ex) {
         m_log.error("caught exception extracting/filtering attributes from query result: %s", ex.what());
         for_each(ctx.getResolvedAttributes().begin(), ctx.getResolvedAttributes().end(), xmltooling::cleanup<shibsp::Attribute>());
         ctx.getResolvedAttributes().clear();
@@ -534,7 +534,7 @@
             client.sendSAML(query, application.getId(), mcc, loc.get());
             srt.reset(client.receiveSAML());
         }
-        catch (const exception& ex) {
+        catch (const std::exception& ex) {
             m_log.error("exception during SAML query to %s: %s", loc.get(), ex.what());
             soaper.reset();
         }
@@ -605,7 +605,7 @@
                     m_log.debugStream() << "decrypted assertion: " << *newtoken << logging::eol;
             }
         }
-        catch (const exception& ex) {
+        catch (const std::exception& ex) {
             m_log.error("failed to decrypt assertion: %s", ex.what());
             throw;
         }
@@ -672,7 +672,7 @@
             }
         }
     }
-    catch (const exception& ex) {
+    catch (const std::exception& ex) {
         m_log.error("assertion failed policy validation: %s", ex.what());
         throw;
     }
@@ -701,7 +701,7 @@
             filter->filterAttributes(fc, ctx.getResolvedAttributes());
         }
     }
-    catch (const exception& ex) {
+    catch (const std::exception& ex) {
         m_log.error("caught exception extracting/filtering attributes from query result: %s", ex.what());
         for_each(ctx.getResolvedAttributes().begin(), ctx.getResolvedAttributes().end(), xmltooling::cleanup<shibsp::Attribute>());
         ctx.getResolvedAttributes().clear();
@@ -742,7 +742,7 @@
             m_log.warn("can't attempt attribute query, either no NameID or no metadata to use");
         }
     }
-    catch (const exception& ex) {
+    catch (const std::exception& ex) {
         // Already logged.
         if (!m_exceptionId.empty()) {
             auto_ptr<SimpleAttribute> attr(new SimpleAttribute(m_exceptionId));
