$NetBSD: patch-src_location_declarativemaps_qdeclarativegeomap.cpp,v 1.1.2.2 2018/07/19 13:48:41 bsiegert Exp $

Build fix with GCC 4.8.

--- src/location/declarativemaps/qdeclarativegeomap.cpp.orig	2018-06-12 18:44:12.000000000 +0000
+++ src/location/declarativemaps/qdeclarativegeomap.cpp
@@ -694,11 +694,11 @@ void QDeclarativeGeoMap::mappingManagerI
     QImage copyrightImage;
     if (!m_initialized && width() > 0 && height() > 0) {
         QMetaObject::Connection copyrightStringCatcherConnection =
-                connect(m_map,
+                connect(m_map.data(),
                         QOverload<const QString &>::of(&QGeoMap::copyrightsChanged),
                         [&copyrightString](const QString &copy){ copyrightString = copy; });
         QMetaObject::Connection copyrightImageCatcherConnection =
-                connect(m_map,
+                connect(m_map.data(),
                         QOverload<const QImage &>::of(&QGeoMap::copyrightsChanged),
                         [&copyrightImage](const QImage &copy){ copyrightImage = copy; });
         m_map->setViewportSize(QSize(width(), height()));
@@ -719,8 +719,8 @@ void QDeclarativeGeoMap::mappingManagerI
         emit m_map->copyrightsChanged(copyrightImage);
 
 
-    connect(m_map, &QGeoMap::sgNodeChanged, this, &QQuickItem::update);
-    connect(m_map, &QGeoMap::cameraCapabilitiesChanged, this, &QDeclarativeGeoMap::onCameraCapabilitiesChanged);
+    connect(m_map.data(), &QGeoMap::sgNodeChanged, this, &QQuickItem::update);
+    connect(m_map.data(), &QGeoMap::cameraCapabilitiesChanged, this, &QDeclarativeGeoMap::onCameraCapabilitiesChanged);
 
     // This prefetches a buffer around the map
     m_map->prefetchData();
