# $NetBSD: Makefile,v 1.3 2010/09/13 14:32:42 taca Exp $

DISTNAME=	merb_test_unit-0.9.13
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.merbivore.com/
COMMENT=	Merb plugin that provides support for Test::Unit
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-merb-core>=0.9.9:../../www/merb-core

CONFLICTS+=	merb-test-unit-[0-9]*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
