# $NetBSD: Makefile,v 1.5 2015/03/13 17:31:37 taca Exp $

DISTNAME=	rack-ssl-1.4.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/josh/rack-ssl
COMMENT=	Rack middleware to force SSL/TLS
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack14>=0:../../www/ruby-rack14

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
