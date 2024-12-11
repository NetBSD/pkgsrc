# $NetBSD: Makefile,v 1.10 2024/12/11 14:04:58 taca Exp $

DISTNAME=	unicode-display_width-3.1.2
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/janlelis/unicode-display_width
COMMENT=	Monospace Unicode character width in Ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-unicode-emoji>=4.0.4<5:../../textproc/ruby-unicode-emoji

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
