# $NetBSD: Makefile,v 1.8 2014/03/26 14:27:23 taca Exp $

DISTNAME=	faraday-0.9.0
CATEGORIES=	www

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	https://github.com/lostisland/faraday
COMMENT=	HTTP/REST API client library
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-multipart-post>=1.2<3:../../www/ruby-multipart-post

RUBY_VERSION_SUPPORTED=	200 193 21

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
