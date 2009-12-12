# $NetBSD: Makefile,v 1.29 2009/12/12 18:03:31 asau Exp $

DISTNAME=	rman-3.2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=polyglotman/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://polyglotman.sourceforge.net/
COMMENT=	Produces HTML from formatted and unformatted man pages

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rman ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/rman.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
