# $NetBSD: Makefile,v 1.13 2019/07/08 16:26:39 leot Exp $

DISTNAME=	net-http-persistent-3.0.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://docs.seattlerb.org/net-http-persistent/
COMMENT=	Manages persistent connections using Net::HTTP
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-connection_pool>=2.2<2.3:../../net/ruby-connection_pool

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
