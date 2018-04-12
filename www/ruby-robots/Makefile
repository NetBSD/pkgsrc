# $NetBSD: Makefile,v 1.1 2018/04/12 15:44:33 minskim Exp $

DISTNAME=	robots-0.10.1
CATEGORIES=	www

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://github.com/fizx/robots
COMMENT=	Parser for robots.txt
LICENSE=	mit

post-extract:
	${CHMOD} -R a+r ${WRKSRC}

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
