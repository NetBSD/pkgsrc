# $NetBSD: Makefile,v 1.21 2023/11/12 13:24:30 wiz Exp $

DISTNAME=	slim-1.4.0
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=slim-fork/}

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://slim-fork.sourceforge.io/
COMMENT=	Simple login manager
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

USE_CMAKE=	yes

AUTO_MKDIRS=	yes
RCD_SCRIPTS+=	slim

SUBST_CLASSES+=		options
SUBST_FILES.options=	slim.conf
SUBST_STAGE.options=	pre-configure
SUBST_VARS.options+=	SLIM_LOGIN_CMD SLIM_XSERVER_ARGUMENTS

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	CMakeLists.txt slim.conf
SUBST_VARS.paths=	PREFIX
SUBST_VARS.paths+=	PKG_SYSCONFDIR
SUBST_VARS.paths+=	X11BASE

.include "../../mk/bsd.prefs.mk"

# Possible todos
# - Install adjusted xinitrc.sample which uses ~/.xsession if present
# - Adjust CMakeLists.txt to find fontconfig

post-install:
	${INSTALL_DATA} ${WRKSRC}/xinitrc.sample ${DESTDIR}${PREFIX}/share/examples/slim

.if ${OPSYS} == "NetBSD"
# Drops the ability to pass theme as %session param to .xinitrc
SLIM_LOGIN_CMD?=		/bin/sh - /etc/X11/xdm/Xsession
SLIM_XSERVER_ARGUMENTS?=	vt05 -noretro -nolisten tcp
.else
SLIM_LOGIN_CMD?=		${TOOLS_PATH.sh} - ~/.xinitrc %session
SLIM_XSERVER_ARGUMENTS?=	-nolisten tcp
.endif

CONF_FILES+=	share/examples/slim/slim.conf \
		${PKG_SYSCONFDIR}/slim.conf

# XXX the slim.sh file installed for rc.d use specifies dbus as a
# dependency, but this isn't reflected below.
.include "options.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
