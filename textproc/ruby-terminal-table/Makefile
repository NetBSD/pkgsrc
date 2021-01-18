# $NetBSD: Makefile,v 1.3 2021/01/18 14:52:59 taca Exp $

DISTNAME=	terminal-table-2.0.0
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tj/terminal-table
COMMENT=	Simple, feature rich ascii table generation library
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-unicode-display_width>=1:../../textproc/ruby-unicode-display_width

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
