# $NetBSD: Makefile,v 1.16 2023/03/16 03:25:41 gutteridge Exp $

DISTNAME=	slim-1.3.6
PKGREVISION=	11
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=slim.berlios/}

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://github.com/iwamatsu/slim
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

.if ${OPSYS} == "NetBSD"
# Drops the ability to pass theme as %session param to .xinitrc
SLIM_LOGIN_CMD?=	/bin/sh - /etc/X11/xdm/Xsession
SLIM_XSERVER_ARGUMENTS?=vt05 -noretro
.else
DEPENDS+=    bash-[0-9]*:../../shells/bash
SLIM_LOGIN_CMD?=	@PREFIX@/bin/bash -login ~/.xinitrc %session
SLIM_XSERVER_ARGUMENTS?=	
.endif

CONF_FILES+=	share/examples/slim/slim.conf \
		${PKG_SYSCONFDIR}/slim.conf

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
