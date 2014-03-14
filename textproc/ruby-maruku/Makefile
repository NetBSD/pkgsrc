# $NetBSD: Makefile,v 1.8 2014/03/14 18:22:03 taca Exp $

DISTNAME=	maruku-0.7.1
CATEGORIES=	textproc

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://maruku.rubyforge.org/
COMMENT=	Markdown-superset interpreter
LICENSE=	gnu-gpl-v2

DEPENDS+=	${RUBY_PKGPREFIX}-syntax>=1.0.0:../../textproc/ruby-syntax

CONFLICTS+=	ruby[1-9][0-9]-maruku-*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
