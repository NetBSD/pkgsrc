# $NetBSD: Makefile,v 1.15 2018/03/17 14:45:05 taca Exp $

DISTNAME=	puma-3.11.3
CATEGORIES=	www

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://puma.io/
COMMENT=	Modern concurrent web server for Ruby
LICENSE=	mit

RUBYGEM_OPTIONS+=	--format-executable
USE_GCC_RUNTIME=	yes

.include "../../lang/ruby/gem.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
