# $NetBSD: Makefile,v 1.6 2020/08/17 20:20:15 leot Exp $

DISTNAME=	coma-1.1
PKGREVISION=	1
CATEGORIES=	wm
MASTER_SITES=	https://coma.one/releases/

MAINTAINER=	fcambus@NetBSD.org
HOMEPAGE=	https://coma.one/releases/
COMMENT=	Keyboard driven tiling window manager
LICENSE=	isc

# Use sh instead of hardcoded zsh
SUBST_CLASSES+=		shell
SUBST_STAGE.shell=	pre-configure
SUBST_MESSAGE.shell=	Use sh instead of hardcoded zsh
SUBST_FILES.shell=	scripts/*
SUBST_SED.shell+=	-e 's,zsh,sh,'

USE_LANGUAGES=	c99
USE_TOOLS+=	pkg-config

MAKE_FLAGS+=	MAN_DIR="${PREFIX}/${PKGMANDIR}"

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
