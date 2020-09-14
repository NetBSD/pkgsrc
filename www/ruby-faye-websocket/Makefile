# $NetBSD: Makefile,v 1.4 2020/09/14 15:28:55 taca Exp $

DISTNAME=	faye-websocket-0.11.0
CATEGORIES=	www

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://github.com/faye/faye-websocket-ruby
COMMENT=	Standards-compliant WebSocket server and client
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-eventmachine>=0.12.0:../../devel/ruby-eventmachine
DEPENDS+=	${RUBY_PKGPREFIX}-websocket-driver>=0.5.1:../../www/ruby-websocket-driver

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
