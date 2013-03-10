# $NetBSD: Makefile,v 1.3 2013/03/10 09:16:46 taca Exp $

DISTNAME=	rack-ssl-1.3.3
PKGREVISION=	1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/josh/rack-ssl
COMMENT=	Rack middleware to force SSL/TLS
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack14>=0:../../www/ruby-rack14

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
