# $NetBSD: Makefile,v 1.4 2021/12/11 14:49:15 taca Exp $

DISTNAME=	em-websocket-0.5.3
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/igrigorik/em-websocket
COMMENT=	EventMachine based WebSocket server
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-eventmachine>=0.12.9:../../devel/ruby-eventmachine
DEPENDS+=	${RUBY_PKGPREFIX}-http_parser.rb>=0.6.0:../../www/ruby-http_parser.rb

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
