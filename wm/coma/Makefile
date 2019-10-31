# $NetBSD: Makefile,v 1.5 2019/10/31 10:30:22 fcambus Exp $

DISTNAME=	coma-1.1
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
