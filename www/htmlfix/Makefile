# $NetBSD: Makefile,v 1.16 2016/07/09 06:39:12 wiz Exp $
#

DISTNAME=		htmlfix-1.03
PKGREVISION=		6
CATEGORIES=		www
MASTER_SITES=		http://www.mono.org/abs/tools/htmlfix/

MAINTAINER=		abs@NetBSD.org
COMMENT=		Fix latin1 to html entities and/or line endings

DEPENDS+=	p5-HTML-FixEntities-[0-9]*:../../www/p5-HTML-FixEntities

USE_TOOLS+=		perl:run
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1
REPLACE_PERL=		htmlfix.pl

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/htmlfix.pl ${DESTDIR}${PREFIX}/bin/htmlfix
	${INSTALL_MAN} ${WRKSRC}/htmlfix.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/htmlfix.1

.include "../../mk/bsd.pkg.mk"
