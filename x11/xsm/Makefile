# $NetBSD: Makefile,v 1.16 2024/03/03 23:59:59 wiz Exp $

DISTNAME=		xsm-1.0.6
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		X Session Manager

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

CONFIGURE_ENV+=		APP_MAN_SUFFIX=1

# Most modern Linuxen don't come with rcmds by default,
# so just pretend to have them to keep configure happy.
.if !exists(/usr/bin/rsh)
CONFIGURE_ENV+=		ac_cv_path_RSH=/usr/bin/rsh
.endif

MAKE_FLAGS+=		appdefaultdir=${PREFIX}/lib/X11/app-defaults
INSTALL_MAKE_FLAGS+=	SYSTEM_INIT_DIR=${PREFIX}/share/examples/xsm

MAKE_DIRS+=		${PKG_SYSCONFDIR}/X11/xsm
CONF_FILES+=		share/examples/xsm/system.xsm ${PKG_SYSCONFDIR}/X11/xsm/system.xsm

.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
