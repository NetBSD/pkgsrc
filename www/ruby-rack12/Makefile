# $NetBSD: Makefile,v 1.2.8.1 2013/01/18 14:21:08 tron Exp $

DISTNAME=	rack-1.2.7
CATEGORIES=	www

# Note: www/ruby-actionpack3needs ruby-rack<1.3.
MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rack.rubyforge.org/
COMMENT=	Ruby webserver interface
LICENSE=	mit

pre-configure:
	${FIND} ${WRKSRC} -type f -exec ${CHMOD} g-w {} \;

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
