# $NetBSD: Makefile,v 1.1.1.1 2004/10/04 20:50:57 cube Exp $
#

DISTNAME=	ion-3ds-20040906
PKGNAME=	${DISTNAME:S/-3ds-/3-/}
CATEGORIES=	wm x11
MASTER_SITES=	http://modeemi.cs.tut.fi/~tuomov/ion/dl/

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://iki.fi/~tuomov/ion/
COMMENT=	Keyboard friendly tiling window manager

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	YES
USE_PKGINSTALL=	YES
USE_X11=	YES
USE_GNU_TOOLS+=	make
GNU_CONFIGURE=	YES
USE_PKGLOCALEDIR=	YES

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
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
			look_simpleblue.lua look_wheat2.lua
.for f in ${EGFILES}
CONF_FILES+=		${EGDIR}/$f ${PKG_SYSCONFDIR}/$f
.endfor
.undef f

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# This is necessary because gettext's builtin.mk add stuff there,
# and ion3's autoconf is rather broken in the way it auto-configures
# itself for gettext.  Eventually ion3 should be fixed, but right now
# it is not really possible.
LIBS=
