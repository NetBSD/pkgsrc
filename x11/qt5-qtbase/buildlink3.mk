# $NetBSD: buildlink3.mk,v 1.13 2016/03/05 11:28:00 jperkin Exp $

BUILDLINK_TREE+=	qt5-qtbase

.if !defined(QT5_QTBASE_BUILDLINK3_MK)
QT5_QTBASE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt5-qtbase+=	qt5-qtbase>=5.5.1
BUILDLINK_ABI_DEPENDS.qt5-qtbase+=	qt5-qtbase>=5.5.1nb4
BUILDLINK_PKGSRCDIR.qt5-qtbase?=	../../x11/qt5-qtbase

BUILDLINK_INCDIRS.qt5-qtbase+=	qt5/include
BUILDLINK_LIBDIRS.qt5-qtbase+=	qt5/lib
BUILDLINK_LIBDIRS.qt5-qtbase+=	qt5/plugins

QTDIR=		${BUILDLINK_PREFIX.qt5-qtbase}/qt5
CMAKE_PREFIX_PATH+=	${QTDIR}

PTHREAD_OPTS+=	require

.include "../../mk/bsd.fast.prefs.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.if ${OPSYS} != "Darwin"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../x11/xcb-util-image/buildlink3.mk"
.include "../../x11/xcb-util-keysyms/buildlink3.mk"
.include "../../x11/xcb-util-wm/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.endif
.endif	# QT5_QTBASE_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt5-qtbase
