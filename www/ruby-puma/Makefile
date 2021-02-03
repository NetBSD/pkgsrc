# $NetBSD: Makefile,v 1.27 2021/02/03 15:47:55 taca Exp $

DISTNAME=	puma-5.2.0
CATEGORIES=	www

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	https://puma.io/
COMMENT=	Modern concurrent web server for Ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-nio4r>=2.0<3:../../net/ruby-nio4r

RUBYGEM_OPTIONS+=	--format-executable
USE_GCC_RUNTIME=	yes

.include "../../lang/ruby/gem.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
