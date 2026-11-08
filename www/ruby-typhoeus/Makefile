# $NetBSD: Makefile,v 1.6 2026/11/08 15:01:56 taca Exp $

DISTNAME=	typhoeus-1.7.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/typhoeus/typhoeus
COMMENT=	Wraps libcurl in order to make fast and reliable requests
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-ethon>=0.19.0<0.20:../../www/ruby-ethon

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
