# $NetBSD: Makefile,v 1.3.2.1 2002/06/23 19:03:52 jlam Exp $
#

DISTNAME=		htmlfix-1.03
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
