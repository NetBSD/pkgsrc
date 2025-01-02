# $NetBSD: Makefile,v 1.11 2025/01/02 06:02:01 taca Exp $

DISTNAME=	unicode-display_width-3.1.3
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/janlelis/unicode-display_width
COMMENT=	Monospace Unicode character width in Ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-unicode-emoji>=4.0.4<5:../../textproc/ruby-unicode-emoji

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
