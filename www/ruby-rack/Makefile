# $NetBSD: Makefile,v 1.11.8.1 2013/01/18 14:21:08 tron Exp $

DISTNAME=	rack-1.4.4
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rack.rubyforge.org/
COMMENT=	Modular Ruby webserver interface
LICENSE=	mit

pre-configure:
	${FIND} ${WRKSRC} -type f -exec ${CHMOD} g-w {} \;

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
