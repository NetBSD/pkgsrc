# $NetBSD: Makefile,v 1.14 2020/03/20 18:00:26 taca Exp $

DISTNAME=	net-http-persistent-3.1.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://docs.seattlerb.org/net-http-persistent/
COMMENT=	Manages persistent connections using Net::HTTP
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-connection_pool>=2.2<2.3:../../net/ruby-connection_pool

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
