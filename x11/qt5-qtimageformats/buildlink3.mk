# $NetBSD: buildlink3.mk,v 1.27 2019/08/09 17:41:40 adam Exp $

BUILDLINK_TREE+=	qt5-qtimageformats

.if !defined(QT5_QTIMAGEFORMATS_BUILDLINK3_MK)
QT5_QTIMAGEFORMATS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt5-qtimageformats+=	qt5-qtimageformats>=5.9.1
BUILDLINK_ABI_DEPENDS.qt5-qtimageformats+=	qt5-qtimageformats>=5.13.0
BUILDLINK_PKGSRCDIR.qt5-qtimageformats?=	../../x11/qt5-qtimageformats

BUILDLINK_INCDIRS.qt5-qtimageformats+=	qt5/include
BUILDLINK_LIBDIRS.qt5-qtimageformats+=	qt5/lib
BUILDLINK_LIBDIRS.qt5-qtimageformats+=	qt5/plugins

.include "../../archivers/xz/buildlink3.mk"
.include "../../graphics/jasper/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/mng/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# QT5_QTIMAGEFORMATS_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt5-qtimageformats
