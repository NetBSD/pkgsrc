# $NetBSD: Makefile,v 1.22 2021/01/16 12:50:18 taca Exp $

DISTNAME=	faraday-1.3.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lostisland/faraday
COMMENT=	HTTP/REST API client library
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-multipart-post>=1.2<3:../../www/ruby-multipart-post
DEPENDS+=	${RUBY_PKGPREFIX}-ruby2_keywords>=0:../../devel/ruby-ruby2_keywords

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
