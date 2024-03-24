# $NetBSD: Makefile,v 1.23 2024/03/24 14:36:30 taca Exp $

DISTNAME=	RedCloth-4.3.4
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
