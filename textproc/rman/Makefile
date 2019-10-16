# $NetBSD: Makefile,v 1.31 2019/10/16 16:30:17 micha Exp $

DISTNAME=	rman-3.2
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=polyglotman/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/polyglotman/
COMMENT=	Produces HTML from formatted and unformatted man pages
LICENSE=	artistic

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rman ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/rman.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
