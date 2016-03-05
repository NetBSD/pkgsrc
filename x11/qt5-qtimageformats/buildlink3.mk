# $NetBSD: buildlink3.mk,v 1.11 2016/03/05 11:28:00 jperkin Exp $

BUILDLINK_TREE+=	qt5-qtimageformats

.if !defined(QT5_QTIMAGEFORMATS_BUILDLINK3_MK)
QT5_QTIMAGEFORMATS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt5-qtimageformats+=	qt5-qtimageformats>=5.5.1
BUILDLINK_ABI_DEPENDS.qt5-qtimageformats+=	qt5-qtimageformats>=5.5.1nb3
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
