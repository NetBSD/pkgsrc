# $NetBSD: Makefile,v 1.6 2014/01/14 08:41:44 obache Exp $

DISTNAME=	faraday-0.8.9
CATEGORIES=	www

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	https://github.com/lostisland/faraday
COMMENT=	HTTP/REST API client library
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-multipart-post>=1.2:../../www/ruby-multipart-post

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
