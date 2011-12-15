# $NetBSD: Makefile,v 1.1.1.1 2011/12/15 15:28:36 taca Exp $

DISTNAME=	rack-cache-1.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rack.rubyforge.org/
COMMENT=	HTTP Caching for Rack
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack>=0.4:../../www/ruby-rack

#pre-configure:
#	${FIND} ${WRKSRC} -type f -exec ${CHMOD} g-w {} \;

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
