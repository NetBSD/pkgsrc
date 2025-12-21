# $NetBSD: buildlink3.mk,v 1.1 2025/12/21 09:38:11 markd Exp $

BUILDLINK_TREE+=	qt6-qtwebengine

.if !defined(QT6_QTWEBENGINE_BUILDLINK3_MK)
QT6_QTWEBENGINE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt6-qtwebengine+=	qt6-qtwebengine>=6.8.2
BUILDLINK_PKGSRCDIR.qt6-qtwebengine?=	../../www/qt6-qtwebengine

.include "../../geography/qt6-qtpositioning/buildlink3.mk"
.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../www/qt6-qtwebchannel/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# QT6_QTWEBENGINE_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt6-qtwebengine
