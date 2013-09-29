$NetBSD: patch-shibsp_attribute_resolver_impl_QueryAttributeResolver.cpp,v 1.1 2013/09/29 10:19:47 joerg Exp $

--- shibsp/attribute/resolver/impl/QueryAttributeResolver.cpp.orig	2013-09-29 08:58:22.000000000 +0000
+++ shibsp/attribute/resolver/impl/QueryAttributeResolver.cpp
@@ -277,7 +277,7 @@ QueryResolver::QueryResolver(const DOMEl
                 }
             }
         }
-        catch (exception& ex) {
+        catch (std::exception& ex) {
             m_log.error("exception loading attribute designator: %s", ex.what());
         }
         child = XMLHelper::getNextSiblingElement(child);
@@ -347,7 +347,7 @@ void QueryResolver::SAML1Query(QueryCont
             client.sendSAML(request, application.getId(), mcc, loc.get());
             response.reset(client.receiveSAML());
         }
-        catch (exception& ex) {
+        catch (std::exception& ex) {
             m_log.error("exception during SAML query to %s: %s", loc.get(), ex.what());
             soaper.reset();
         }
@@ -393,7 +393,7 @@ void QueryResolver::SAML1Query(QueryCont
         if (!policy->isAuthenticated())
             throw SecurityPolicyException("Security of SAML 1.x query result not established.");
     }
-    catch (exception& ex) {
+    catch (std::exception& ex) {
         m_log.error("assertion failed policy validation: %s", ex.what());
         throw;
     }
@@ -435,7 +435,7 @@ void QueryResolver::SAML1Query(QueryCont
             filter->filterAttributes(fc, ctx.getResolvedAttributes());
         }
     }
-    catch (exception& ex) {
+    catch (std::exception& ex) {
         m_log.error("caught exception extracting/filtering attributes from query result: %s", ex.what());
         for_each(ctx.getResolvedAttributes().begin(), ctx.getResolvedAttributes().end(), xmltooling::cleanup<shibsp::Attribute>());
         ctx.getResolvedAttributes().clear();
@@ -517,7 +517,7 @@ void QueryResolver::SAML2Query(QueryCont
             client.sendSAML(query, application.getId(), mcc, loc.get());
             srt.reset(client.receiveSAML());
         }
-        catch (exception& ex) {
+        catch (std::exception& ex) {
             m_log.error("exception during SAML query to %s: %s", loc.get(), ex.what());
             soaper.reset();
         }
@@ -581,7 +581,7 @@ void QueryResolver::SAML2Query(QueryCont
                     m_log.debugStream() << "decrypted assertion: " << *newtoken << logging::eol;
             }
         }
-        catch (exception& ex) {
+        catch (std::exception& ex) {
             m_log.error("failed to decrypt assertion: %s", ex.what());
             throw;
         }
@@ -648,7 +648,7 @@ void QueryResolver::SAML2Query(QueryCont
             }
         }
     }
-    catch (exception& ex) {
+    catch (std::exception& ex) {
         m_log.error("assertion failed policy validation: %s", ex.what());
         throw;
     }
@@ -677,7 +677,7 @@ void QueryResolver::SAML2Query(QueryCont
             filter->filterAttributes(fc, ctx.getResolvedAttributes());
         }
     }
-    catch (exception& ex) {
+    catch (std::exception& ex) {
         m_log.error("caught exception extracting/filtering attributes from query result: %s", ex.what());
         for_each(ctx.getResolvedAttributes().begin(), ctx.getResolvedAttributes().end(), xmltooling::cleanup<shibsp::Attribute>());
         ctx.getResolvedAttributes().clear();
@@ -716,7 +716,7 @@ void QueryResolver::resolveAttributes(Re
             m_log.warn("can't attempt attribute query, either no NameID or no metadata to use");
         }
     }
-    catch (exception& ex) {
+    catch (std::exception& ex) {
         // Already logged.
         if (!m_exceptionId.empty()) {
             auto_ptr<SimpleAttribute> attr(new SimpleAttribute(m_exceptionId));
