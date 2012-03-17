# $NetBSD: Makefile,v 1.11 2012/03/17 16:42:00 taca Exp $

DISTNAME=	rack-1.4.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rack.rubyforge.org/
COMMENT=	Modular Ruby webserver interface
LICENSE=	mit

pre-configure:
	${FIND} ${WRKSRC} -type f -exec ${CHMOD} g-w {} \;

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
