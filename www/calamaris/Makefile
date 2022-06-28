# $NetBSD: Makefile,v 1.23 2022/06/28 11:37:02 wiz Exp $

DISTNAME=	calamaris-2.59
PKGREVISION=	10
CATEGORIES=	www
MASTER_SITES=	http://cord.de/tools/squid/calamaris/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cord.de/tools/squid/calamaris/
COMMENT=	Squid logfile analyzer

USE_TOOLS+=	perl:run
REPLACE_PERL=	calamaris
NO_BUILD=	YES

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/calamaris

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/calamaris ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/calamaris.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
.for doc in CHANGES COPYRIGHT EXAMPLES README
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DESTDIR}${PREFIX}/share/doc/calamaris
.endfor

.include "../../mk/bsd.pkg.mk"
