# $NetBSD: Makefile,v 1.1 2013/01/26 08:50:53 obache Exp $

DISTNAME=	faraday-0.8.4
CATEGORIES=	www

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://github.com/lostsland/faraday
COMMENT=	HTTP/REST API client library
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-multipart-post>=1.1:../../www/ruby-multipart-post

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
