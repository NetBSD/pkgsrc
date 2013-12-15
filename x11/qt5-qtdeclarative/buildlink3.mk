# $NetBSD: buildlink3.mk,v 1.2 2013/12/15 09:42:44 ryoon Exp $

BUILDLINK_TREE+=	qt5-qtdeclarative

.if !defined(QT5_QTDECLARATIVE_BUILDLINK3_MK)
QT5_QTDECLARATIVE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt5-qtdeclarative+=	qt5-qtdeclarative>=5.2.0
BUILDLINK_PKGSRCDIR.qt5-qtdeclarative?=	../../x11/qt5-qtdeclarative

BUILDLINK_INCDIRS.qt5-qtdeclarative+=	qt5/include
BUILDLINK_LIBDIRS.qt5-qtdeclarative+=	qt5/lib
BUILDLINK_LIBDIRS.qt5-qtdeclarative+=	qt5/plugins

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtxmlpatterns/buildlink3.mk"
.endif	# QT5_QTDECLARATIVE_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt5-qtdeclarative
