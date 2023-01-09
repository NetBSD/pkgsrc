# $NetBSD: Makefile,v 1.3 2023/01/09 12:50:54 taca Exp $

DISTNAME=	faraday-net_http_persistent-2.1.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lostisland/faraday-net_http_persistent
COMMENT=	Faraday adapter for NetHttpPersistent
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-faraday>=2.5<3:../../www/ruby-faraday
DEPENDS+=	${RUBY_PKGPREFIX}-net-http-persistent>=4.0<5:../../www/ruby-net-http-persistent

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
