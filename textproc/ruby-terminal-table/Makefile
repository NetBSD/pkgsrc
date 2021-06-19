# $NetBSD: Makefile,v 1.4 2021/06/19 07:47:33 taca Exp $

DISTNAME=	terminal-table-2.0.0
PKGREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tj/terminal-table
COMMENT=	Simple, feature rich ascii table generation library
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-unicode-display_width>=1:../../textproc/ruby-unicode-display_width

USE_LANGUAGES=	# none

OVERRIDE_GEMSPEC+=	unicode-display_width>=1

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
