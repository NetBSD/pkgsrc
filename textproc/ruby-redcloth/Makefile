# $NetBSD: Makefile,v 1.21 2020/01/26 17:32:18 rillig Exp $

DISTNAME=	RedCloth-4.3.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://redcloth.org/
COMMENT=	Textile library for Ruby
LICENSE=	mit

USE_GCC_RUNTIME=	yes
RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
