# $NetBSD: Makefile,v 1.12 2014/03/13 11:08:53 jperkin Exp $

DISTNAME=	hpricot-0.8.6
CATEGORIES=	textproc

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://wiki.github.com/hpricot/hpricot
COMMENT=	Fast, enjoyable HTML parser for Ruby
LICENSE=	mit

USE_GCC_RUNTIME=	yes

post-extract:
	${FIND} ${WRKSRC} -type f -exec ${CHMOD} g-w {} \;

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
