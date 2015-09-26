# $NetBSD: Makefile,v 1.10 2015/09/26 23:41:54 taca Exp $

DISTNAME=	maruku-0.7.2
CATEGORIES=	textproc

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/bhollis/maruku
COMMENT=	Markdown-superset interpreter
LICENSE=	gnu-gpl-v2

DEPENDS+=	${RUBY_PKGPREFIX}-syntax>=1.0.0:../../textproc/ruby-syntax

CONFLICTS+=	ruby[1-9][0-9]-maruku-*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
