# $NetBSD: Makefile,v 1.7 2012/10/29 05:06:41 asau Exp $

DISTNAME=	mxterm_129
PKGREVISION=	3
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	x11
MASTER_SITES=	http://www.unixdev.net/downloads/mxterm/129/

MAINTAINER=	inittab@unixdev.net
#HOMEPAGE=	http://www.fh-wilhelmshaven.de/~akcaagaa/index_mxterm.html
HOMEPAGE=	http://www.unixdev.net/projects/mxterm
COMMENT=	Motif XTerm

GNU_CONFIGURE=	YES

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
