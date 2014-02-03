# $NetBSD: buildlink3.mk,v 1.3 2014/02/03 16:17:12 ryoon Exp $

BUILDLINK_TREE+=	qt5-qtimageformats

.if !defined(QT5_QTIMAGEFORMATS_BUILDLINK3_MK)
QT5_QTIMAGEFORMATS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt5-qtimageformats+=	qt5-qtimageformats>=5.2.0
BUILDLINK_ABI_DEPENDS.qt5-qtimageformats?=	qt5-qtimageformats>=5.2.0nb2
BUILDLINK_PKGSRCDIR.qt5-qtimageformats?=	../../x11/qt5-qtimageformats

BUILDLINK_INCDIRS.qt5-qtimageformats+=	qt5/include
BUILDLINK_LIBDIRS.qt5-qtimageformats+=	qt5/lib
BUILDLINK_LIBDIRS.qt5-qtimageformats+=	qt5/plugins

.include "../../archivers/xz/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# QT5_QTIMAGEFORMATS_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt5-qtimageformats
