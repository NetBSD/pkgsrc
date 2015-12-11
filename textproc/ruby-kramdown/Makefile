# $NetBSD: Makefile,v 1.13 2015/12/11 11:46:31 wiz Exp $

DISTNAME=	kramdown-1.9.0
PKGREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://kramdown.gettalong.org/
COMMENT=	Pure-Ruby Markdown-superset parser and converter
LICENSE=	mit

RUBYGEM_OPTIONS+=	--format-executable
FILES_SUBST+=		RUBY_SUFFIX=${RUBY_SUFFIX}

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
