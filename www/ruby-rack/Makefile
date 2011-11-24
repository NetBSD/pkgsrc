# $NetBSD: Makefile,v 1.8 2011/11/24 14:21:55 taca Exp $

DISTNAME=	rack-1.2.4
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
