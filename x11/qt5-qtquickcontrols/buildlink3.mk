# $NetBSD: buildlink3.mk,v 1.1 2013/12/13 14:38:36 ryoon Exp $

BUILDLINK_TREE+=	qt5-qtquickcontrols

.if !defined(QT5_QTQUICKCONTROLS_BUILDLINK3_MK)
QT5_QTQUICKCONTROLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt5-qtquickcontrols+=	qt5-qtquickcontrols>=5.1.1
BUILDLINK_PKGSRCDIR.qt5-qtquickcontrols?=	../../x11/qt5-qtquickcontrols

BUILDLINK_INCDIRS.qt5-qtquickcontrols+=	qt5/include
BUILDLINK_LIBDIRS.qt5-qtquickcontrols+=	qt5/lib
BUILDLINK_LIBDIRS.qt5-qtquickcontrols+=	qt5/plugins

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.endif	# QT5_QTQUICKCONTROLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt5-qtquickcontrols
