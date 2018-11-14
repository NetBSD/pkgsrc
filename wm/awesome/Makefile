# $NetBSD: Makefile,v 1.65 2018/11/14 22:22:32 kleink Exp $

DISTNAME=	awesome-4.2
PKGREVISION=	5
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_GITHUB:=awesomeWM/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pallegra@gmail.com
HOMEPAGE=	https://awesomewm.org/
COMMENT=	Tiling window manager based on dwm
LICENSE=	gnu-gpl-v2

CONFLICTS+=	awesome<3.0

USE_TOOLS+=	bash gmake pkg-config
USE_CMAKE=	yes
USE_LANGUAGES=	c c++
REPLACE_BASH+=	utils/awesome-client

.include "../../wm/awesome/options.mk"

PKG_SYSCONFSUBDIR=	xdg/awesome

CONFIGURE_DIRS=	${WRKDIR}/build
CMAKE_ARG_PATH=	${WRKSRC}

CMAKE_ARGS+=	-DCOMPRESS_MANPAGES=${MANZ:Q}
CMAKE_ARGS+=	-DAWESOME_MAN_PATH=${PREFIX}/${PKGMANDIR}
CMAKE_ARGS+=	-DOVERRIDE_VERSION=${PKGVERSION_NOREV}
CMAKE_ARGS+=	-DLUA_INCLUDE_DIR=${PREFIX}/${LUA_INCDIR}

EGDIR=		${PREFIX}/share/examples/awesome
CONF_FILES=	${EGDIR}/rc.lua ${PKG_SYSCONFDIR}/rc.lua

SUBST_CLASSES+=		eg
SUBST_MESSAGE.eg=	Fixing pathnames
SUBST_STAGE.eg=		pre-configure
SUBST_FILES.eg=		CMakeLists.txt
SUBST_SED.eg=		-e "s,\$${AWESOME_SYSCONFDIR},${EGDIR},"

SUBST_CLASSES+=		lua
SUBST_MESSAGE.lua=	Fixing lua prefix
SUBST_STAGE.lua=	pre-configure
SUBST_FILES.lua=	CMakeLists.txt awesomeConfig.cmake build-utils/lgi-check.sh \
			tests/examples/CMakeLists.txt
SUBST_SED.lua=		-e "s,@LUA_INTERPRETER@,${LUA_INTERPRETER},"

SUBST_CLASSES+=		ldoc
SUBST_MESSAGE.ldoc=	Fixing ldoc executable
SUBST_STAGE.ldoc=	pre-configure
SUBST_FILES.ldoc=	awesomeConfig.cmake
SUBST_SED.ldoc=		-e "s,@LDOC_EXECUTABLE@,ldoc${_LUA_DOT_VERSION},"

BUILD_DEPENDS+=		ImageMagick-[0-9]*:../../graphics/ImageMagick
BUILD_DEPENDS+=		asciidoc>=8.3.0:../../textproc/asciidoc
BUILD_DEPENDS+=		xmlto-[0-9]*:../../textproc/xmlto
BUILD_DEPENDS+=		docbook-xml-[0-9]*:../../textproc/docbook-xml

DEPENDS+=		${LUA_PKGPREFIX}-gi>=0.7.0:../../devel/lua-gi

pre-configure:
	${RUN} mkdir -p ${WRKDIR}/build

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/cairo-gobject/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/libxdg-basedir/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../x11/xcb-util-cursor/buildlink3.mk"
.include "../../x11/xcb-util-keysyms/buildlink3.mk"
.include "../../x11/xcb-util-wm/buildlink3.mk"
.include "../../x11/xcb-util-xrm/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
