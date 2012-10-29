# $NetBSD: Makefile,v 1.17 2012/10/29 05:06:57 asau Exp $

DISTNAME=	xaniroc
PKGNAME=	xaniroc-1.02
PKGREVISION=	4
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.42.org/pub/orphan/
EXTRACT_SUFX=	.src.tar.Z

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Animate your root-cursor

USE_IMAKE=	yes

post-extract:
	${MV} ${WRKSRC}/manpage.1 ${WRKSRC}/xaniroc.man

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
