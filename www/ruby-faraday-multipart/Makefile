# $NetBSD: Makefile,v 1.2 2025/01/02 06:07:39 taca Exp $

DISTNAME=	faraday-multipart-1.1.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lostisland/faraday-multipart
COMMENT=	Perform multipart-post requests using Faraday
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-multipart-post>=2<3:../../www/ruby-multipart-post

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
