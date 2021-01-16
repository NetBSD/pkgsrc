# $NetBSD: Makefile,v 1.16 2021/01/16 12:59:46 taca Exp $

DISTNAME=	net-http-persistent-4.0.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://docs.seattlerb.org/net-http-persistent/
COMMENT=	Manages persistent connections using Net::HTTP
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-connection_pool>=2.2<2.3:../../net/ruby-connection_pool

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
