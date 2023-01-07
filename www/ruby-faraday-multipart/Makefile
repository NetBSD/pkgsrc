# $NetBSD: Makefile,v 1.1 2023/01/07 15:20:12 taca Exp $

DISTNAME=	faraday-multipart-1.0.4
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lostisland/faraday-multipart
COMMENT=	Perform multipart-post requests using Faraday
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-multipart-post>=2<3:../../www/ruby-multipart-post

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
