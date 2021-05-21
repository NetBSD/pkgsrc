# $NetBSD: Makefile,v 1.12 2021/05/21 11:19:22 nia Exp $

DISTNAME=	maruku-0.7.3
PKGREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/bhollis/maruku
COMMENT=	Markdown-superset interpreter
LICENSE=	gnu-gpl-v2

DEPENDS+=	${RUBY_PKGPREFIX}-syntax>=1.0.0:../../textproc/ruby-syntax

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
