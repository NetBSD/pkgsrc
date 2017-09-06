# $NetBSD: Makefile,v 1.2 2017/09/06 10:40:34 wiz Exp $

GITHUB_PROJECT=	opt
GITHUB_TAG=	43d57505564617b33946f6a56850d764cb4a6f74
# Date of the latest git commit
DISTNAME=	wmutils-opt-0.20161004
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_GITHUB:=wmutils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://wmutils.io/
COMMENT=	Optional addons to wmutils
LICENSE=	isc

EXTRACT_USING=	bsdtar

USE_TOOLS+=	gmake

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	MANPREFIX=${PREFIX}/${PKGMANDIR}

.include "../../x11/libxcb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
