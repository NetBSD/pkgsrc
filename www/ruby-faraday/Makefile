# $NetBSD: Makefile,v 1.5 2013/08/01 12:53:26 obache Exp $

DISTNAME=	faraday-0.8.8
CATEGORIES=	www

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	https://github.com/lostisland/faraday
COMMENT=	HTTP/REST API client library
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-multipart-post>=1.2:../../www/ruby-multipart-post

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
