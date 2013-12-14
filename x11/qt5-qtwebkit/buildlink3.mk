# $NetBSD: buildlink3.mk,v 1.2 2013/12/14 07:35:04 wiz Exp $

BUILDLINK_TREE+=	qt5-qtwebkit

.if !defined(QT5_QTWEBKIT_BUILDLINK3_MK)
QT5_QTWEBKIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt5-qtwebkit+=	qt5-qtwebkit>=5.2.0rc1
BUILDLINK_PKGSRCDIR.qt5-qtwebkit?=	../../x11/qt5-qtwebkit

BUILDLINK_INCDIRS.qt5-qtwebkit+=	qt5/include
BUILDLINK_LIBDIRS.qt5-qtwebkit+=	qt5/lib
BUILDLINK_LIBDIRS.qt5-qtwebkit+=	qt5/plugins

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../x11/qt5-qtlocation/buildlink3.mk"
.include "../../x11/qt5-qtmultimedia/buildlink3.mk"
.include "../../x11/qt5-qtsensors/buildlink3.mk"
.include "../../lang/python/tool.mk"
BUILDLINK_DEPMETHOD.ruby=       build
.include "../../lang/ruby/buildlink3.mk"
.endif	# QT5_QTWEBKIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt5-qtwebkit
