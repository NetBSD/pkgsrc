# $NetBSD: Makefile,v 1.14 2025/09/15 16:55:30 taca Exp $

DISTNAME=	unicode-display_width-3.2.0
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/janlelis/unicode-display_width
COMMENT=	Monospace Unicode character width in Ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-unicode-emoji>=4.1<5:../../textproc/ruby-unicode-emoji

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
