# $NetBSD: buildlink3.mk,v 1.3 2023/10/07 20:00:35 adam Exp $

BUILDLINK_TREE+=	qt5-qtwebengine

.if !defined(QT5_QTWEBENGINE_BUILDLINK3_MK)
QT5_QTWEBENGINE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt5-qtwebengine+=	qt5-qtwebengine>=5.15.2
BUILDLINK_ABI_DEPENDS.qt5-qtwebengine+=	qt5-qtwebengine>=5.15.11
BUILDLINK_PKGSRCDIR.qt5-qtwebengine?=	../../x11/qt5-qtwebengine

.endif	# QT5_QTWEBENGINE_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt5-qtwebengine
