# $NetBSD: Makefile,v 1.2 2010/09/12 02:53:26 taca Exp $

DISTNAME=	merb_test_unit-0.9.13
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.merbivore.com/
COMMENT=	Merb plugin that provides support for Test::Unit
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-merb-core>=0.9.9:../../www/merb-core

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
