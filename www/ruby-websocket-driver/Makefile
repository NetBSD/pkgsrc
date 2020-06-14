# $NetBSD: Makefile,v 1.5 2020/06/14 15:51:21 taca Exp $

DISTNAME=	websocket-driver-0.7.2
CATEGORIES=	www

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://github.com/faye/websocket-driver-ruby
COMMENT=	WebSocket protocol handler with pluggable I/O
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-websocket-extensions>=0.1.0:../../www/ruby-websocket-extensions

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
