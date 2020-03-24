# $NetBSD: Makefile,v 1.2 2020/03/24 16:52:47 taca Exp $

DISTNAME=	kramdown-parser-gfm-1.1.0
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kramdown/parser-gfm
COMMENT=	Kramdown parser for the GFM dialect of Markdown
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-kramdown>=2.0<3:../../textproc/ruby-kramdown

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
