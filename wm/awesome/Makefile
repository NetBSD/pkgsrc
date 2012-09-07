# $NetBSD: Makefile,v 1.29 2012/09/07 19:17:38 adam Exp $
#

DISTNAME=	awesome-3.4.13
PKGREVISION=	1
CATEGORIES=	x11 wm
MASTER_SITES=	http://awesome.naquadah.org/download/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pallegra@gmail.com
HOMEPAGE=	http://awesome.naquadah.org/
COMMENT=	Tiling window manager based on dwm
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=	awesome<3.0

USE_TOOLS+=	bash gmake pkg-config
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

PKG_SYSCONFSUBDIR=	xdg/awesome

CMAKE_ARGS+=	-DWITH_DBUS=OFF
CMAKE_ARGS+=	-DSYSCONFDIR=${PKG_SYSCONFDIR:C/\/xdg\/awesome//}
CMAKE_ARGS+=	-DCOMPRESS_MANPAGES=${MANZ:Q}
CMAKE_ARGS+=	-DAWESOME_MAN_PATH=${PREFIX}/${PKGMANDIR}

REPLACE_BASH+=	build-utils/gperf.sh

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
SUBST_SED.ev=		-e "s,PKGPREFIX,${PREFIX},"

BUILD_DEPENDS+=	ImageMagick-[0-9]*:../../graphics/ImageMagick
BUILD_DEPENDS+=	asciidoc>=8.3.0:../../textproc/asciidoc
BUILD_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto
BUILD_DEPENDS+=	docbook-xml-[0-9]*:../../textproc/docbook-xml


.include "../../devel/gperf/buildlink3.mk"
.include "../../devel/libev/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../x11/libxdg-basedir/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../x11/xcb-util-image/buildlink3.mk"
.include "../../x11/xcb-util-keysyms/buildlink3.mk"
.include "../../x11/xcb-util-wm/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
