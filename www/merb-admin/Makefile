# $NetBSD: Makefile,v 1.2 2011/06/19 08:47:18 taca Exp $

DISTNAME=	merb-admin-0.8.8
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rubygems.org/gems/merb-admin
COMMENT=	Plugin provides easy-to-use interface for managing your data
LICENSE=	mit

DEPENDS+=       ${RUBY_PKGPREFIX}-builder>=2.1:../../textproc/ruby-builder
DEPENDS+=       ${RUBY_PKGPREFIX}-merb-assets>=1.1:../../www/merb-assets
DEPENDS+=       ${RUBY_PKGPREFIX}-merb-helpers>=1.1:../../www/merb-helpers
DEPENDS+=       ${RUBY_PKGPREFIX}-merb-slices>=1.1:../../www/merb-slices

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
