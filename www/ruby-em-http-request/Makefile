# $NetBSD: Makefile,v 1.3 2016/01/03 07:56:35 taca Exp $

DISTNAME=	em-http-request-1.1.3
CATEGORIES=	net

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/igrigorik/em-http-request
COMMENT=	EventMachine based, async HTTP Request client
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-eventmachine>=1.0.3:../../devel/ruby-eventmachine
DEPENDS+=	${RUBY_PKGPREFIX}-addressable>=2.3.4:../../net/ruby-addressable
DEPENDS+=	${RUBY_PKGPREFIX}-http_parser.rb>=0.6.0:../../www/ruby-http_parser.rb
DEPENDS+=	${RUBY_PKGPREFIX}-em-socksify>=0.3:../../net/ruby-em-socksify
DEPENDS+=	${RUBY_PKGPREFIX}-cookiejar>=0:../../www/ruby-cookiejar

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
