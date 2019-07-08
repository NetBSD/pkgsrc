# $NetBSD: Makefile,v 1.13 2019/07/08 10:47:26 nia Exp $

DISTNAME=	hpricot-0.8.6
CATEGORIES=	textproc

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/hpricot/hpricot/wiki
COMMENT=	Fast, enjoyable HTML parser for Ruby
LICENSE=	mit

USE_GCC_RUNTIME=	yes

post-extract:
	${FIND} ${WRKSRC} -type f -exec ${CHMOD} g-w {} \;

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
