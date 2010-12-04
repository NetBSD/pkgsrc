# $NetBSD: Makefile,v 1.7 2010/12/04 04:33:51 taca Exp $

DISTNAME=	hpricot-0.8.3
CATEGORIES=	textproc

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://wiki.github.com/hpricot/hpricot
COMMENT=	Fast, enjoyable HTML parser for Ruby
LICENSE=	mit

post-extract:
	${FIND} ${WRKSRC} -type f -exec ${CHMOD} g-w {} \;

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
