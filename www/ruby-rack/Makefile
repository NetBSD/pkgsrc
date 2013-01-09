# $NetBSD: Makefile,v 1.12 2013/01/09 11:24:37 taca Exp $

DISTNAME=	rack-1.4.3
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rack.rubyforge.org/
COMMENT=	Modular Ruby webserver interface
LICENSE=	mit

pre-configure:
	${FIND} ${WRKSRC} -type f -exec ${CHMOD} g-w {} \;

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
