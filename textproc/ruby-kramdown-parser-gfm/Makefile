# $NetBSD: Makefile,v 1.1 2019/10/05 04:44:53 ryoon Exp $

DISTNAME=	kramdown-parser-gfm-1.0.1
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kramdown/parser-gfm
COMMENT=	Kramdown parser for the GFM dialect of Markdown
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-kramdown>=2.0<3:../../textproc/ruby-kramdown

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
