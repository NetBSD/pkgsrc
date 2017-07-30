# $NetBSD: Makefile,v 1.2 2017/07/30 22:32:28 wiz Exp $

DISTNAME=	websocket-driver-0.6.5
CATEGORIES=	www

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://github.com/faye/websocket-driver-ruby
COMMENT=	WebSocket protocol handler with pluggable I/O
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-websocket-extensions>=0.1.0:../../www/ruby-websocket-extensions

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
