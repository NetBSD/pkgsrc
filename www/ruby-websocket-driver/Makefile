# $NetBSD: Makefile,v 1.3 2017/09/18 01:11:36 taca Exp $

DISTNAME=	websocket-driver-0.7.0
CATEGORIES=	www

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://github.com/faye/websocket-driver-ruby
COMMENT=	WebSocket protocol handler with pluggable I/O
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-websocket-extensions>=0.1.0:../../www/ruby-websocket-extensions

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
