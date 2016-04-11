# $NetBSD: buildlink3.mk,v 1.6 2016/04/11 19:01:41 ryoon Exp $

BUILDLINK_TREE+=	qt5-qtwebchannel

.if !defined(QT5_QTWEBCHANNEL_BUILDLINK3_MK)
QT5_QTWEBCHANNEL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt5-qtwebchannel+=	qt5-qtwebchannel>=5.5.1
BUILDLINK_ABI_DEPENDS.qt5-qtwebchannel+=	qt5-qtwebchannel>=5.5.1nb3
BUILDLINK_PKGSRCDIR.qt5-qtwebchannel?=	../../x11/qt5-qtwebchannel

BUILDLINK_INCDIRS.qt5-qtwebchannel+=	qt5/include
BUILDLINK_LIBDIRS.qt5-qtwebchannel+=	qt5/lib
BUILDLINK_LIBDIRS.qt5-qtwebchannel+=	qt5/plugins

.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.endif	# QT5_QTWEBCHANNEL_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt5-qtwebchannel
