# $NetBSD: Makefile,v 1.4 2014/03/21 01:06:47 taca Exp $

DISTNAME=	rack-ssl-1.3.3
PKGREVISION=	2
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/josh/rack-ssl
COMMENT=	Rack middleware to force SSL/TLS
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack14>=0:../../www/ruby-rack14

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
