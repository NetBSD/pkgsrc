# $NetBSD: Makefile,v 1.3 2015/12/13 17:22:07 taca Exp $

DISTNAME=	classifier-1.3.4
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	# http://classifier.rufy.com/
COMMENT=	General classifier module for Bayesian and other classificaions
LICENSE=	gnu-lgpl-v2.1

DEPENDS=	${RUBY_PKGPREFIX}-fast-stemmer>=1.0.0:../../textproc/ruby-fast-stemmer

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
