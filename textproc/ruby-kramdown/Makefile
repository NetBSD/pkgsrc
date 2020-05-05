# $NetBSD: Makefile,v 1.23 2020/05/05 06:01:51 taca Exp $

DISTNAME=	kramdown-2.2.1
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://kramdown.gettalong.org/
COMMENT=	Pure-Ruby Markdown-superset parser and converter
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rexml:../../textproc/ruby-rexml

RUBYGEM_OPTIONS+=	--format-executable

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
