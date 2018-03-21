# $NetBSD: Makefile,v 1.2 2018/03/21 14:14:49 taca Exp $

DISTNAME=	em-websocket-0.5.1
PKGREVISION=	1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/igrigorik/em-websocket
COMMENT=	EventMachine based WebSocket server
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-eventmachine>=0.12.9:../../devel/ruby-eventmachine
DEPENDS+=	${RUBY_PKGPREFIX}-http_parser.rb>=0.6.0<0.7:../../www/ruby-http_parser.rb

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
