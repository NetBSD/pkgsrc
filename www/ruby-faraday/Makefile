# $NetBSD: Makefile,v 1.19 2018/09/23 16:51:55 taca Exp $

DISTNAME=	faraday-0.15.3
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lostisland/faraday
COMMENT=	HTTP/REST API client library
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-multipart-post>=1.2<3:../../www/ruby-multipart-post

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
