# $NetBSD: Makefile,v 1.2 2021/02/14 15:34:38 taca Exp $

DISTNAME=	ethon-0.12.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/typhoeus/ethon
COMMENT=	Very lightweight libcurl wrapper
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-ffi>=1.3.0:../../devel/ruby-ffi
DEPENDS+=	curl-[0-9]*:../../www/curl

USE_LANGUAGES=	# empty

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
