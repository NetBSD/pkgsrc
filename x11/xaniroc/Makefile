# $NetBSD: Makefile,v 1.9 2005/03/24 21:13:04 wiz Exp $

DISTNAME=	xaniroc
PKGNAME=	xaniroc-1.02
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.freebird.org/unixware/freebird/x11/utils/ \
		ftp://netlab1.usu.edu/pub/mirror/freebird/x11/utils/
EXTRACT_SUFX=	.src.tar.Z

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Animate your root-cursor

USE_IMAKE=	yes

post-extract:
	${MV} ${WRKSRC}/manpage.1 ${WRKSRC}/xaniroc.man

.include "../../mk/bsd.pkg.mk"
