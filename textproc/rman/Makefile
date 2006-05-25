# $NetBSD: Makefile,v 1.28 2006/05/25 10:41:21 wiz Exp $

DISTNAME=	rman-3.2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=polyglotman/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://polyglotman.sourceforge.net/
COMMENT=	Produces HTML from formatted and unformatted man pages

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rman ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/rman.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
