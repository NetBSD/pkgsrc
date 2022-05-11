# $NetBSD: Makefile,v 1.9 2022/05/11 07:50:07 fcambus Exp $

DISTNAME=	coma-1.1
PKGREVISION=	1
CATEGORIES=	wm
MASTER_SITES=	https://coma.one/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://coma.one/wm/
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

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Linux"
.  include "../../devel/libbsd/buildlink3.mk"
.endif
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
