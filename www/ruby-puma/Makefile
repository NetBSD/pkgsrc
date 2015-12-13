# $NetBSD: Makefile,v 1.11 2015/12/13 16:09:19 taca Exp $

DISTNAME=	puma-2.15.3
CATEGORIES=	www

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://puma.io/
COMMENT=	Modern concurrent web server for Ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack>=1.2<2:../../www/ruby-rack

RUBYGEM_OPTIONS+=	--format-executable
USE_GCC_RUNTIME=	yes

.include "../../lang/ruby/gem.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
