# $NetBSD: Makefile,v 1.7 2014/01/17 08:36:59 obache Exp $

DISTNAME=	faraday-0.9.0
CATEGORIES=	www

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	https://github.com/lostisland/faraday
COMMENT=	HTTP/REST API client library
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-multipart-post>=1.2<3:../../www/ruby-multipart-post

RUBY_VERSION_SUPPORTED=	200 193

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
