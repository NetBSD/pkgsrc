# $NetBSD: buildlink3.mk,v 1.9 2016/03/05 11:28:01 jperkin Exp $

BUILDLINK_TREE+=	qt5-sqlite3

.if !defined(QT5_SQLITE3_BUILDLINK3_MK)
QT5_SQLITE3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt5-sqlite3+=	qt5-sqlite3>=5.5.1
BUILDLINK_ABI_DEPENDS.qt5-sqlite3+=	qt5-sqlite3>=5.5.1nb2
BUILDLINK_PKGSRCDIR.qt5-sqlite3?=	../../x11/qt5-sqlite3

BUILDLINK_LIBDIRS.qt5-sqlite3+=		qt5/plugins

.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# QT5_SQLITE3_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt5-sqlite3
