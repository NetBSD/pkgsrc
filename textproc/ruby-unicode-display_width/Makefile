# $NetBSD: Makefile,v 1.12 2025/01/19 16:37:25 taca Exp $

DISTNAME=	unicode-display_width-3.1.4
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/janlelis/unicode-display_width
COMMENT=	Monospace Unicode character width in Ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-unicode-emoji>=4.0.4<5:../../textproc/ruby-unicode-emoji

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
