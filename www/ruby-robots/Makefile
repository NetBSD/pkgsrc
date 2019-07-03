# $NetBSD: Makefile,v 1.2 2019/07/03 07:19:04 nia Exp $

DISTNAME=	robots-0.10.1
CATEGORIES=	www

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/fizx/robots
COMMENT=	Parser for robots.txt
LICENSE=	mit

post-extract:
	${CHMOD} -R a+r ${WRKSRC}

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
