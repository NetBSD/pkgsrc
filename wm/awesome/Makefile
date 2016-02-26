# $NetBSD: Makefile,v 1.55 2016/02/26 13:56:50 jperkin Exp $
#

DISTNAME=	awesome-3.5.5
PKGREVISION=	4
CATEGORIES=	x11 wm
MASTER_SITES=	http://awesome.naquadah.org/download/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pallegra@gmail.com
HOMEPAGE=	http://awesome.naquadah.org/
COMMENT=	Tiling window manager based on dwm
LICENSE=	gnu-gpl-v2

CONFLICTS+=	awesome<3.0
LUA_VERSIONS_INCOMPATIBLE=52

USE_TOOLS+=	bash gmake pkg-config
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

PKG_SYSCONFSUBDIR=	xdg/awesome

CMAKE_ARGS+=	-DWITH_DBUS=OFF
CMAKE_ARGS+=	-DSYSCONFDIR=${PKG_SYSCONFDIR:C/\/xdg\/awesome//}
CMAKE_ARGS+=	-DCOMPRESS_MANPAGES=${MANZ:Q}
CMAKE_ARGS+=	-DAWESOME_MAN_PATH=${PREFIX}/${PKGMANDIR}

EGDIR=		${PREFIX}/share/examples/awesome
CONF_FILES=	${EGDIR}/rc.lua ${PKG_SYSCONFDIR}/rc.lua

SUBST_CLASSES+=		eg
SUBST_MESSAGE.eg=	Fixing pathnames
SUBST_STAGE.eg=		pre-configure
SUBST_FILES.eg=		CMakeLists.txt
SUBST_SED.eg=		-e "s,\$${AWESOME_SYSCONFDIR},${EGDIR},"

SUBST_CLASSES+=		ev
SUBST_MESSAGE.ev=	Fixing pathnames for libev
SUBST_STAGE.ev=		pre-configure
SUBST_FILES.ev=		awesomeConfig.cmake
SUBST_SED.ev=		-e "s,@LIBEV_PREFIX@,${BUILDLINK_PREFIX.libev},"

BUILD_DEPENDS+=	ImageMagick-[0-9]*:../../graphics/ImageMagick
BUILD_DEPENDS+=	asciidoc>=8.3.0:../../textproc/asciidoc
BUILD_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto
BUILD_DEPENDS+=	docbook-xml-[0-9]*:../../textproc/docbook-xml

DEPENDS+=		lua51-gi>=0.7.0:../../devel/lua-gi
DEPENDS+=		pango>=1.29.4nb2:../../devel/pango

LDFLAGS.Darwin+=	-liconv
LDFLAGS.SunOS+=		-liconv

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libev/buildlink3.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/cairo-gobject/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../lang/lua51/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/libxdg-basedir/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../x11/xcb-util-cursor/buildlink3.mk"
.include "../../x11/xcb-util-keysyms/buildlink3.mk"
.include "../../x11/xcb-util-wm/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
