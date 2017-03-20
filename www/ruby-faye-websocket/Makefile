# $NetBSD: Makefile,v 1.2 2017/03/20 14:03:56 tsutsui Exp $

DISTNAME=	faye-websocket-0.10.7
CATEGORIES=	www

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://github.com/faye/faye-websocket-ruby
COMMENT=	Standards-compliant WebSocket server and client
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-eventmachine>=0.12.0:../../devel/ruby-eventmachine
DEPENDS+=	${RUBY_PKGPREFIX}-websocket-driver>=0.5.1:../../www/ruby-websocket-driver

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
