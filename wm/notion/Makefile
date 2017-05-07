# $NetBSD: Makefile,v 1.23 2017/05/07 16:10:35 wiz Exp $

DISTNAME=	notion-3-2017050501
PKGNAME=	${DISTNAME:S/3-/3./}
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_GITHUB:=raboof/}
GITHUB_TAG=	${DISTNAME:S/notion-//}

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://notion.sourceforge.net/
COMMENT=	Tiling window manager based on ion3
LICENSE=	ion-license AND gnu-lgpl-v2.1

# notion is based on ion3
CONFLICTS=	ion3-[0-9]*

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}
USE_LANGUAGES=	c99
USE_TOOLS+=	gmake msgfmt pax pkg-config

LUA_VERSIONS_INCOMPATIBLE=	53

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	EXAMPLEDIR=${PREFIX}/share/examples/notion
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}
MAKE_FLAGS+=	X11_PREFIX=${BUILDLINK_PREFIX.libX11}
MAKE_FLAGS+=	X11_LIBS="${COMPILER_RPATH_FLAG}${X11_PREFIX}/lib -L${X11_PREFIX}/lib -lX11 -lXext"
MAKE_FLAGS+=	LUA_INTERPRETER=${LUA_INTERPRETER}
MAKE_FLAGS+=	LUA_COMPILER=${LUA_COMPILER}
MAKE_FLAGS+=	LUA_VERSION=${_LUA_DOT_VERSION}

EGDIR=		${PREFIX}/share/examples/notion
EGFILES=	cfg_defaults.lua
EGFILES+=	cfg_dock.lua
EGFILES+=	cfg_kludges.lua
EGFILES+=	cfg_layouts.lua
EGFILES+=	cfg_menu.lua
EGFILES+=	cfg_notion.lua
EGFILES+=	cfg_notioncore.lua
EGFILES+=	cfg_query.lua
EGFILES+=	cfg_sp.lua
EGFILES+=	cfg_statusbar.lua
EGFILES+=	cfg_tiling.lua
EGFILES+=	cfg_xrandr.lua
EGFILES+=	look.lua
EGFILES+=	look_brownsteel.lua
EGFILES+=	look_clean.lua
EGFILES+=	look_cleanios.lua
EGFILES+=	look_cleanviolet.lua
EGFILES+=	look_dusky.lua
EGFILES+=	look_greenlight.lua
EGFILES+=	look_greyviolet.lua
EGFILES+=	look_ios.lua
EGFILES+=	look_newviolet.lua
EGFILES+=	look_simpleblue.lua
EGFILES+=	lookcommon_clean.lua
EGFILES+=	lookcommon_emboss.lua

PKG_SYSCONFSUBDIR=	notion
INSTALLATION_DIRS=	${EGDIR}

.for f in ${EGFILES}
CONF_FILES+=	${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor

# Abuse buildlink to add required libraries.
BUILDLINK_TRANSFORM.SunOS+=	opt:-Wl,--as-needed:-lsocket
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,-whole-archive
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,-no-whole-archive

post-install:
	cd ${WRKSRC} && pax -rw contrib ${DESTDIR}${EGDIR}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
