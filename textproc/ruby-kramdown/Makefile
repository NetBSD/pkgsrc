# $NetBSD: Makefile,v 1.24 2020/05/05 06:13:05 taca Exp $

DISTNAME=	kramdown-2.2.1
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://kramdown.gettalong.org/
COMMENT=	Pure-Ruby Markdown-superset parser and converter
LICENSE=	mit

RUBYGEM_OPTIONS+=	--format-executable

USE_LANGUAGES=	# none

.include "../../lang/ruby/rubyversion.mk"
.if ${RUBY_VER} < 26
DEPENDS+=	${RUBY_PKGPREFIX}-rexml:../../textproc/ruby-rexml
.endif

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
