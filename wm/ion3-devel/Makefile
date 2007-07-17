# $NetBSD: Makefile,v 1.23 2007/07/17 20:20:08 joerg Exp $
#

DISTNAME=	ion-3rc-20070708
PKGNAME=	${DISTNAME:S/-3ds-/3-/}
PKGREVISION=	1
CATEGORIES=	wm x11
MASTER_SITES=	http://modeemi.fi/~tuomov/dl/

MAINTAINER=	philip@FreeBSD.org
HOMEPAGE=	http://modeemi.fi/~tuomov/ion/
COMMENT=	Keyboard friendly tiling window manager

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake msgfmt
USE_PKGLOCALEDIR=	YES

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ENV+=		PKGLOCALEDIR=${PREFIX}/${PKGLOCALEDIR}/locale

PKG_SYSCONFSUBDIR=	ion3
EGDIR=			${PREFIX}/share/examples/ion3
EGFILES=		cfg_defaults.lua cfg_dock.lua cfg_ioncore.lua	\
			cfg_ion.lua cfg_kludges.lua cfg_layouts.lua	\
			cfg_menu.lua cfg_pwm.lua cfg_query.lua 		\
			cfg_sp.lua cfg_statusbar.lua cfg_tiling.lua	\
			look.lua look_brownsteel.lua			\
			look_clean.lua look_cleanios.lua 		\
			look_cleanviolet.lua look_dusky.lua		\
			look_greenlight.lua look_greyviolet.lua		\
			look_ios.lua look_newviolet.lua			\
			look_simpleblue.lua lookcommon_clean.lua	\
			lookcommon_emboss.lua
.for f in ${EGFILES}
CONF_FILES+=		${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor

INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
