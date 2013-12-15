# $NetBSD: buildlink3.mk,v 1.2 2013/12/15 09:42:44 ryoon Exp $

BUILDLINK_TREE+=	qt5-qtbase

.if !defined(QT5_QTBASE_BUILDLINK3_MK)
QT5_QTBASE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt5-qtbase+=	qt5-qtbase>=5.2.0
BUILDLINK_PKGSRCDIR.qt5-qtbase?=	../../x11/qt5-qtbase

BUILDLINK_INCDIRS.qt5-qtbase+=	qt5/include
BUILDLINK_LIBDIRS.qt5-qtbase+=	qt5/lib
BUILDLINK_LIBDIRS.qt5-qtbase+=	qt5/plugins

QTDIR=		${BUILDLINK_PREFIX.qt5-qtbase}/qt5

PTHREAD_OPTS+=	require

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
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
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.endif	# QT5_QTBASE_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt5-qtbase
