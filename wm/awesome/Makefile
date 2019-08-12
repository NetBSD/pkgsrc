# $NetBSD: Makefile,v 1.69 2019/08/12 20:51:48 nia Exp $

DISTNAME=	awesome-4.3
PKGREVISION=	1
CATEGORIES=	wm
EXTRACT_SUFX=	.tar.xz
MASTER_SITES=	${MASTER_SITE_GITHUB:=awesomeWM/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pallegra@gmail.com
HOMEPAGE=	https://awesomewm.org/
COMMENT=	Tiling window manager based on dwm
LICENSE=	gnu-gpl-v2

CONFLICTS+=	awesome<3.0

USE_TOOLS+=	bash pkg-config
USE_CMAKE=	yes
USE_LANGUAGES=	c c++
REPLACE_BASH+=	utils/awesome-client

.include "../../wm/awesome/options.mk"

PKG_SYSCONFSUBDIR=	xdg/awesome

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	${WRKSRC}

.include "../../lang/lua/luaversion.mk"

CMAKE_ARGS+=	-DCOMPRESS_MANPAGES=${MANZ:Q}
CMAKE_ARGS+=	-DAWESOME_MAN_PATH=${PREFIX}/${PKGMANDIR}
CMAKE_ARGS+=	-DOVERRIDE_VERSION=${PKGVERSION_NOREV}
CMAKE_ARGS+=	-DLUA_INCLUDE_DIR=${PREFIX}/${LUA_INCDIR}
CMAKE_ARGS+=	-DXDG_CONFIG_DIR=${PKG_SYSCONFBASEDIR}/xdg
CMAKE_ARGS+=	-DGENERATE_DOC=OFF

EGDIR=		${PREFIX}/share/examples/awesome
CONF_FILES=	${EGDIR}/rc.lua ${PKG_SYSCONFDIR}/rc.lua

TOOL_DEPENDS+=	ImageMagick-[0-9]*:../../graphics/ImageMagick
DEPENDS+=	${LUA_PKGPREFIX}-gi>=0.7.0:../../devel/lua-gi

SUBST_CLASSES+=		lua
SUBST_STAGE.lua=	pre-configure
SUBST_MESSAGE.lua=	Fixing lua executable name.
SUBST_FILES.lua+=	awesomeConfig.cmake
SUBST_SED.lua=		-e 's|COMMAND lua|COMMAND ${LUA_INTERPRETER}|g'

pre-configure:
	${RUN} mkdir -p ${WRKSRC}/build

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
