# $NetBSD: Makefile,v 1.22 2023/12/17 15:54:25 taca Exp $

DISTNAME=	RedCloth-4.3.3
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jgarber/redcloth
COMMENT=	Textile library for Ruby
LICENSE=	mit

USE_GCC_RUNTIME=	yes
RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
