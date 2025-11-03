# $NetBSD: Makefile,v 1.7 2025/11/03 05:54:27 taca Exp $

DISTNAME=	ethon-0.18.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/typhoeus/ethon
COMMENT=	Very lightweight libcurl wrapper
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-ffi>=1.15.0:../../devel/ruby-ffi

USE_LANGUAGES=	# empty

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
