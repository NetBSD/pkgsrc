# $NetBSD: buildlink3.mk,v 1.3 2014/02/03 16:17:12 ryoon Exp $

BUILDLINK_TREE+=	qt5-qtlocation

.if !defined(QT5_QTLOCATION_BUILDLINK3_MK)
QT5_QTLOCATION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt5-qtlocation+=	qt5-qtlocation>=5.2.0
BUILDLINK_ABI_DEPENDS.qt5-qtlocation?=	qt5-qtlocation>=5.2.0nb2
BUILDLINK_PKGSRCDIR.qt5-qtlocation?=	../../x11/qt5-qtlocation

BUILDLINK_INCDIRS.qt5-qtlocation+=	qt5/include
BUILDLINK_LIBDIRS.qt5-qtlocation+=	qt5/lib
BUILDLINK_LIBDIRS.qt5-qtlocation+=	qt5/plugins

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.endif	# QT5_QTLOCATION_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt5-qtlocation
