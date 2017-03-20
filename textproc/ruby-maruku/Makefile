# $NetBSD: Makefile,v 1.11 2017/03/20 15:35:24 taca Exp $

DISTNAME=	maruku-0.7.3
CATEGORIES=	textproc

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/bhollis/maruku
COMMENT=	Markdown-superset interpreter
LICENSE=	gnu-gpl-v2

DEPENDS+=	${RUBY_PKGPREFIX}-syntax>=1.0.0:../../textproc/ruby-syntax

CONFLICTS+=	ruby[1-9][0-9]-maruku-*

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
