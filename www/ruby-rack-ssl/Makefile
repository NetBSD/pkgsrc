# $NetBSD: Makefile,v 1.1.1.1 2011/12/15 15:29:27 taca Exp $

DISTNAME=	rack-ssl-1.3.2
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/josh/rack-ssl
COMMENT=	Rack middleware to force SSL/TLS
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack>=0:../../www/ruby-rack

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
