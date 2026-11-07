# $NetBSD: Makefile,v 1.8 2026/11/07 15:54:34 taca Exp $

DISTNAME=	ethon-0.19.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/typhoeus/ethon
COMMENT=	Very lightweight libcurl wrapper
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-ffi>=1.15.0:../../devel/ruby-ffi

USE_LANGUAGES=	# empty

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
