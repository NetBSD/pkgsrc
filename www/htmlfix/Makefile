# $NetBSD: Makefile,v 1.7 2005/07/16 01:19:25 jlam Exp $
#

DISTNAME=		htmlfix-1.03
CATEGORIES=		www
MASTER_SITES=		http://www.mono.org/abs/tools/htmlfix/

MAINTAINER=		abs@NetBSD.org
COMMENT=		Fix latin1 to html entities and/or line endings

DEPENDS+=	p5-HTML-FixEntities-[0-9]*:../../www/p5-HTML-FixEntities

USE_TOOLS+=		perl:run
INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/htmlfix.pl ${PREFIX}/bin/htmlfix
	${INSTALL_MAN} ${WRKSRC}/htmlfix.1 ${PREFIX}/man/man1/htmlfix.1

.include "../../mk/bsd.pkg.mk"
