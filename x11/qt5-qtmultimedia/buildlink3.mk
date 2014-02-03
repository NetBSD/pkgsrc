# $NetBSD: buildlink3.mk,v 1.3 2014/02/03 16:17:12 ryoon Exp $

BUILDLINK_TREE+=	qt5-qtmultimedia

.if !defined(QT5_QTMULTIMEDIA_BUILDLINK3_MK)
QT5_QTMULTIMEDIA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt5-qtmultimedia+=	qt5-qtmultimedia>=5.2.0
BUILDLINK_ABI_DEPENDS.qt5-qtmultimedia?=	qt5-qtmultimedia>=5.2.0nb3
BUILDLINK_PKGSRCDIR.qt5-qtmultimedia?=	../../x11/qt5-qtmultimedia

BUILDLINK_INCDIRS.qt5-qtmultimedia+=	qt5/include
BUILDLINK_LIBDIRS.qt5-qtmultimedia+=	qt5/lib
BUILDLINK_LIBDIRS.qt5-qtmultimedia+=	qt5/plugins

.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../audio/openal/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.endif	# QT5_QTMULTIMEDIA_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt5-qtmultimedia
