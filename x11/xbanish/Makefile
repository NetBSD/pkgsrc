# $NetBSD: Makefile,v 1.1 2020/01/31 17:27:16 pho Exp $

GITHUB_PROJECT=	xbanish
GITHUB_TAG=	v1.6
DISTNAME=	v1.6
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME:S,^v,,}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=jcs/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	https://github.com/jcs/xbanish/
COMMENT=	Banish the mouse cursor when typing
LICENSE=	modified-bsd

WRKSRC=	${WRKDIR}/${PKGNAME_NOREV}

MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}/man1
MAKE_FLAGS+=	LDPATH=${X11_LDFLAGS:Q}

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
