# $NetBSD: Makefile,v 1.6 2022/09/02 17:10:06 wiz Exp $

DISTNAME=	classifier-reborn-2.3.0
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jekyll/classifier-reborn/
COMMENT=	General classifier module for Bayesian and other classificaions
LICENSE=	gnu-lgpl-v2.1

DEPENDS=	${RUBY_PKGPREFIX}-fast-stemmer>=1.0<2:../../textproc/ruby-fast-stemmer

RUBYGEM_OPTIONS+=	--format-executable

RUBY_VERSIONS_INCOMPATIBLE=	26 # ruby-matrix

.include "../../lang/ruby/rubyversion.mk"

.if ${RUBY_VER} != 31
DEPENDS+=	${RUBY_PKGPREFIX}-matrix>=0.4:../../math/ruby-matrix
.endif

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
