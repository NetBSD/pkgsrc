# $NetBSD: buildlink3.mk,v 1.46 2022/06/28 11:37:58 wiz Exp $

BUILDLINK_TREE+=	qt5-qtbase

.if !defined(QT5_QTBASE_BUILDLINK3_MK)
QT5_QTBASE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt5-qtbase+=	qt5-qtbase>=5.9.1
BUILDLINK_ABI_DEPENDS.qt5-qtbase+=	qt5-qtbase>=5.15.4nb1
BUILDLINK_PKGSRCDIR.qt5-qtbase?=	../../x11/qt5-qtbase

BUILDLINK_INCDIRS.qt5-qtbase+=	qt5/include
BUILDLINK_LIBDIRS.qt5-qtbase+=	qt5/lib
BUILDLINK_LIBDIRS.qt5-qtbase+=	qt5/plugins

QTDIR=		${BUILDLINK_PREFIX.qt5-qtbase}/qt5
CMAKE_PREFIX_PATH+=	${QTDIR}

CONFIGURE_ENV+=	QTDIR=${QTDIR}
MAKE_ENV+=	QTDIR=${QTDIR}

CONFIGURE_ENV+=	MOC="${QTDIR}/bin/moc"
MAKE_ENV+=	MOC="${QTDIR}/bin/moc"

PTHREAD_OPTS+=	require

pkgbase := qt5-qtbase
.include "../../mk/pkg-build-options.mk"

BUILDLINK_FILES.qt5-qtbase+=	qt5/bin/moc
BUILDLINK_FILES.qt5-qtbase+=	qt5/bin/qlalr
BUILDLINK_FILES.qt5-qtbase+=	qt5/bin/qmake
BUILDLINK_FILES.qt5-qtbase+=	qt5/bin/qvkgen
BUILDLINK_FILES.qt5-qtbase+=	qt5/bin/rcc
BUILDLINK_FILES.qt5-qtbase+=	qt5/bin/syncqt.pl
BUILDLINK_FILES.qt5-qtbase+=	qt5/bin/tracegen
BUILDLINK_FILES.qt5-qtbase+=	qt5/bin/uic

.if ${PKG_BUILD_OPTIONS.qt5-qtbase:Mdbus}
BUILDLINK_FILES.qt5-qtbase+=	qt5/bin/qdbuscpp2xml
BUILDLINK_FILES.qt5-qtbase+=	qt5/bin/qdbusxml2cpp
.include "../../sysutils/dbus/buildlink3.mk"
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../www/libproxy/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.if ${OPSYS} != "Darwin"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../x11/xcb-util-image/buildlink3.mk"
.include "../../x11/xcb-util-keysyms/buildlink3.mk"
.include "../../x11/xcb-util-renderutil/buildlink3.mk"
.include "../../x11/xcb-util-wm/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.endif
.endif	# QT5_QTBASE_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt5-qtbase
