# $NetBSD: Makefile,v 1.13 2008/04/16 05:34:51 obache Exp $

DISTNAME=	xaniroc
PKGNAME=	xaniroc-1.02
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.42.org/pub/orphan/
EXTRACT_SUFX=	.src.tar.Z

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Animate your root-cursor

USE_IMAKE=	yes

post-extract:
	${MV} ${WRKSRC}/manpage.1 ${WRKSRC}/xaniroc.man

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
