# $NetBSD: Makefile,v 1.5 2022/12/04 16:32:33 taca Exp $

DISTNAME=	terminal-table-3.0.2
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tj/terminal-table
COMMENT=	Simple, feature rich ascii table generation library
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-unicode-display_width>=1.1.1:../../textproc/ruby-unicode-display_width

USE_LANGUAGES=	# none

OVERRIDE_GEMSPEC+=	unicode-display_width>=1

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
