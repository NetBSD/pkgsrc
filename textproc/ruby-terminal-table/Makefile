# $NetBSD: Makefile,v 1.2 2020/06/21 14:54:51 taca Exp $

DISTNAME=	terminal-table-1.8.0
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tj/terminal-table
COMMENT=	Simple, feature rich ascii table generation library
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-unicode-display_width>=1:../../textproc/ruby-unicode-display_width

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
