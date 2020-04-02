# $NetBSD: buildlink3.mk,v 1.43 2020/04/02 22:05:58 adam Exp $

BUILDLINK_TREE+=	qt5-qtmultimedia

.if !defined(QT5_QTMULTIMEDIA_BUILDLINK3_MK)
QT5_QTMULTIMEDIA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt5-qtmultimedia+=	qt5-qtmultimedia>=5.9.1
BUILDLINK_ABI_DEPENDS.qt5-qtmultimedia+=	qt5-qtmultimedia>=5.14.2
BUILDLINK_PKGSRCDIR.qt5-qtmultimedia?=		../../x11/qt5-qtmultimedia

BUILDLINK_INCDIRS.qt5-qtmultimedia+=	qt5/include
BUILDLINK_LIBDIRS.qt5-qtmultimedia+=	qt5/lib
BUILDLINK_LIBDIRS.qt5-qtmultimedia+=	qt5/plugins

pkgbase := qt5-qtmultimedia
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.qt5-qtmultimedia:Mgstreamer)
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.endif
.if !empty(PKG_BUILD_OPTIONS.qt5-qtmultimedia:Mopenal)
.include "../../audio/openal-soft/buildlink3.mk"
.endif
.if !empty(PKG_BUILD_OPTIONS.qt5-qtmultimedia:Mpulseaudio)
.include "../../audio/pulseaudio/buildlink3.mk"
.endif
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.endif	# QT5_QTMULTIMEDIA_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt5-qtmultimedia
