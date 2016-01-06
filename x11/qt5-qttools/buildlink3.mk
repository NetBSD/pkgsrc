# $NetBSD: buildlink3.mk,v 1.16 2016/01/06 10:46:50 adam Exp $

BUILDLINK_TREE+=	qt5-qttools

.if !defined(QT5_QTTOOLS_BUILDLINK3_MK)
QT5_QTTOOLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt5-qttools+=	qt5-qttools>=5.5.1
BUILDLINK_ABI_DEPENDS.qt5-qttools+=	qt5-qttools>=5.5.1nb1
BUILDLINK_PKGSRCDIR.qt5-qttools?=	../../x11/qt5-qttools

BUILDLINK_INCDIRS.qt5-qttools+=	qt5/include
BUILDLINK_LIBDIRS.qt5-qttools+=	qt5/lib
BUILDLINK_LIBDIRS.qt5-qttools+=	qt5/plugins

.include "../../x11/qt5-qtxmlpatterns/buildlink3.mk"
.include "../../x11/qt5-qtwebkit/buildlink3.mk"
.include "../../x11/qt5-sqlite3/buildlink3.mk"
.endif	# QT5_QTTOOLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt5-qttools
