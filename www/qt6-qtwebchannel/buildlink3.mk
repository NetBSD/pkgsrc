# $NetBSD: buildlink3.mk,v 1.15 2025/04/24 14:16:06 wiz Exp $

BUILDLINK_TREE+=	qt6-qtwebchannel

.if !defined(QT6_QTWEBCHANNEL_BUILDLINK3_MK)
QT6_QTWEBCHANNEL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt6-qtwebchannel+=	qt6-qtwebchannel>=6.4.1
BUILDLINK_ABI_DEPENDS.qt6-qtwebchannel+=	qt6-qtwebchannel>=6.8.3nb2
BUILDLINK_PKGSRCDIR.qt6-qtwebchannel?=		../../www/qt6-qtwebchannel

.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# QT6_QTWEBCHANNEL_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt6-qtwebchannel
