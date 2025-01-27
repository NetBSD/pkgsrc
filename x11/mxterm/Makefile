# $NetBSD: Makefile,v 1.11 2025/01/27 18:59:08 rillig Exp $

DISTNAME=	mxterm_129
PKGNAME=	${DISTNAME:S/_/-/}
PKGREVISION=	4
CATEGORIES=	x11
#MASTER_SITES=	http://www.unixdev.net/downloads/mxterm/129/

MAINTAINER=	inittab@unixdev.net
#HOMEPAGE=	http://www.fh-wilhelmshaven.de/~akcaagaa/index_mxterm.html
#HOMEPAGE=	http://www.unixdev.net/projects/mxterm
COMMENT=	Motif XTerm

GNU_CONFIGURE=	YES

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
