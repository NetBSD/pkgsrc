# $NetBSD: buildlink3.mk,v 1.39 2023/11/08 13:21:39 wiz Exp $

BUILDLINK_TREE+=	qt5-qtwebchannel

.if !defined(QT5_QTWEBCHANNEL_BUILDLINK3_MK)
QT5_QTWEBCHANNEL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt5-qtwebchannel+=	qt5-qtwebchannel>=5.9.1
BUILDLINK_ABI_DEPENDS.qt5-qtwebchannel+=	qt5-qtwebchannel>=5.15.11nb2
BUILDLINK_PKGSRCDIR.qt5-qtwebchannel?=		../../x11/qt5-qtwebchannel

BUILDLINK_INCDIRS.qt5-qtwebchannel+=	qt5/include
BUILDLINK_LIBDIRS.qt5-qtwebchannel+=	qt5/lib
BUILDLINK_LIBDIRS.qt5-qtwebchannel+=	qt5/plugins

.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.endif	# QT5_QTWEBCHANNEL_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt5-qtwebchannel
