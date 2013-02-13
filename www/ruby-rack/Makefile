# $NetBSD: Makefile,v 1.11.8.2 2013/02/13 14:58:55 tron Exp $

DISTNAME=	rack-1.4.5
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rack.github.com/
COMMENT=	Modular Ruby webserver interface
LICENSE=	mit

pre-configure:
	${FIND} ${WRKSRC} -type f -exec ${CHMOD} g-w {} \;

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
