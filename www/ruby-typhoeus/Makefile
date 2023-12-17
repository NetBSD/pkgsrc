# $NetBSD: Makefile,v 1.3 2023/12/17 16:47:13 taca Exp $

DISTNAME=	typhoeus-1.4.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/typhoeus/typhoeus
COMMENT=	Wraps libcurl in order to make fast and reliable requests
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-ethon>=0.9.0:../../www/ruby-ethon

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
