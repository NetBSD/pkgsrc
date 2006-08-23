# $NetBSD: Makefile,v 1.15 2006/08/23 18:55:57 wiz Exp $
#

DISTNAME=	ion-3ds-20060524
PKGNAME=	${DISTNAME:S/-3ds-/3-/}
CATEGORIES=	wm x11
MASTER_SITES=	http://iki.fi/tuomov/dl/

MAINTAINER=	rpaulo@NetBSD.org
HOMEPAGE=	http://iki.fi/~tuomov/ion/
COMMENT=	Keyboard friendly tiling window manager

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=		gmake msgfmt
USE_PKGLOCALEDIR=	YES

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ENV+=		PKGLOCALEDIR=${PREFIX}/${PKGLOCALEDIR}/locale

PKG_SYSCONFSUBDIR=	ion3
EGDIR=			${PREFIX}/share/examples/ion3
EGFILES=		cfg_bindings.lua cfg_dock.lua cfg_floatws.lua	\
			cfg_ion.lua cfg_ionws.lua cfg_kludges.lua	\
			cfg_menu.lua cfg_menus.lua cfg_panews.lua	\
			cfg_pwm.lua cfg_pwm_bindings.lua		\
			cfg_pwm_menus.lua cfg_query.lua cfg_sp.lua	\
			cfg_statusbar.lua				\
			dock-draw.lua look.lua look_brownsteel.lua	\
			look_clean.lua look_cleanios.lua		\
			look_cleanviolet.lua look_dusky.lua		\
			look_greyviolet.lua look_ios.lua		\
			look_simpleblue.lua look_wheat2.lua		\
			lookcommon_clean.lua lookcommon_emboss.lua
.for f in ${EGFILES}
CONF_FILES+=		${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
