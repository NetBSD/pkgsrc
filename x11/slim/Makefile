# $NetBSD: Makefile,v 1.5 2019/06/18 16:54:07 nia Exp $

DISTNAME=	slim-1.3.6
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=slim.berlios/}

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://github.com/iwamatsu/slim
COMMENT=	Simple login manager
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

USE_CMAKE=	yes
CMAKE_ARGS=	-DUSE_CONSOLEKIT:Bool=Yes

AUTO_MKDIRS=	yes
RCD_SCRIPTS+=	slim

DEPENDS+=	bash-[0-9]*:../../shells/bash

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	CMakeLists.txt slim.conf
SUBST_VARS.paths=	PREFIX
SUBST_VARS.paths+=	PKG_SYSCONFDIR
SUBST_VARS.paths+=	X11BASE

CONF_FILES+=	share/examples/slim/slim.conf \
		${PKG_SYSCONFDIR}/slim.conf

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../sysutils/consolekit/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
