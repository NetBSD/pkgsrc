# $NetBSD: Makefile,v 1.4 2018/03/14 15:40:07 taca Exp $

DISTNAME=	classifier-reborn-2.2.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jekyll/classifier-reborn/
COMMENT=	General classifier module for Bayesian and other classificaions
LICENSE=	gnu-lgpl-v2.1

DEPENDS=	${RUBY_PKGPREFIX}-fast-stemmer>=1.0<2:../../textproc/ruby-fast-stemmer

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
