# $NetBSD: Makefile,v 1.2 2021/06/02 15:00:15 taca Exp $

DISTNAME=	typhoeus-1.4.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/typhoeus/typhoeus
COMMENT=	Wraps libcurl in order to make fast and reliable requests
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-ethon>=0.9.0:../../www/ruby-ethon

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
