# $NetBSD: Makefile,v 1.20 2020/03/21 17:07:23 taca Exp $

DISTNAME=	faraday-0.17.3
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lostisland/faraday
COMMENT=	HTTP/REST API client library
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-multipart-post>=1.2<3:../../www/ruby-multipart-post

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
