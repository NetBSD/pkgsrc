# $NetBSD: Makefile,v 1.1.1.1 2012/01/08 15:22:14 wiz Exp $
#

DISTNAME=	notion-3-2011102900-src
PKGNAME=	${DISTNAME:S/3-/3./:S/-src//}
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=notion/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://notion.sourceforge.net/
COMMENT=	Tiling window manager based on ion3
LICENSE=	ion-license AND gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

# notion is based on ion3
CONFLICTS=	ion3-[0-9]*

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}
USE_TOOLS+=	gmake msgfmt pkg-config
MAKE_FLAGS+=	X11_PREFIX=${BUILDLINK_PREFIX.libX11}

EGDIR=		${PREFIX}/share/examples/notion
EGFILES=	cfg_defaults.lua
EGFILES+=	cfg_dock.lua
EGFILES+=	cfg_kludges.lua
EGFILES+=	cfg_layouts.lua
EGFILES+=	cfg_menu.lua
EGFILES+=	cfg_notion.lua
EGFILES+=	cfg_notioncore.lua
EGFILES+=	cfg_pwm.lua
EGFILES+=	cfg_query.lua
EGFILES+=	cfg_sp.lua
EGFILES+=	cfg_statusbar.lua
EGFILES+=	cfg_tiling.lua
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

.for f in ${EGFILES}
CONF_FILES+=	${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
