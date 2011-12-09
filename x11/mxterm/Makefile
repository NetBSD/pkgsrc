# $NetBSD: Makefile,v 1.6 2011/12/09 14:36:36 drochner Exp $

DISTNAME=	mxterm_129
PKGREVISION=	3
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	x11
MASTER_SITES=	http://www.unixdev.net/downloads/mxterm/129/

MAINTAINER=	inittab@unixdev.net
#HOMEPAGE=	http://www.fh-wilhelmshaven.de/~akcaagaa/index_mxterm.html
HOMEPAGE=	http://www.unixdev.net/projects/mxterm
COMMENT=	Motif XTerm

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
