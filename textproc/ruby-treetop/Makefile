# $NetBSD: Makefile,v 1.14 2026/01/18 14:26:18 taca Exp $

DISTNAME=	treetop-1.6.18
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cjheath/treetop
COMMENT=	Ruby-based text parsing and interpretation DSL
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-polyglot>=0.3.1<1:../../devel/ruby-polyglot

RUBYGEM_OPTIONS+=	--format-executable
OVERRIDE_GEMSPEC+=	polyglot:

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
