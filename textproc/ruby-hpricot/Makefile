# $NetBSD: Makefile,v 1.7.2.1 2011/02/27 00:26:27 tron Exp $

DISTNAME=	hpricot-0.8.3
PKGREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://wiki.github.com/hpricot/hpricot
COMMENT=	Fast, enjoyable HTML parser for Ruby
LICENSE=	mit

post-extract:
	${FIND} ${WRKSRC} -type f -exec ${CHMOD} g-w {} \;

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
