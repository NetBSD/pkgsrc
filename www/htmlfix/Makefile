# $NetBSD: Makefile,v 1.2 2002/02/13 23:41:59 abs Exp $
#

DISTNAME=		htmlfix-1.01
CATEGORIES=		www
MASTER_SITES=		http://www.mono.org/abs/tools/htmlfix/

MAINTAINER=		abs@netbsd.org
COMMENT=		Fix latin1 to html entities and/or line endings

DEPENDS+=	p5-HTML-FixEntities-[0-9]*:../../www/p5-HTML-FixEntities

USE_PERL5=		YES

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/htmlfix.pl ${PREFIX}/bin/htmlfix
	${INSTALL_MAN} ${WRKSRC}/htmlfix.1 ${PREFIX}/man/man1/htmlfix.1

.include "../../mk/bsd.pkg.mk"
