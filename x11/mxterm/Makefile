# $NetBSD: Makefile,v 1.3 2006/02/05 23:11:40 joerg Exp $

DISTNAME=	mxterm_129
PKGREVISION=	2
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
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
