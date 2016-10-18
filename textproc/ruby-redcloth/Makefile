# $NetBSD: Makefile,v 1.20 2016/10/18 14:43:14 taca Exp $

DISTNAME=	RedCloth-4.3.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://redcloth.org/
COMMENT=	Textile library for Ruby
LICENSE=	mit

USE_GCC_RUNTIME=	yes
RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
