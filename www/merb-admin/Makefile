# $NetBSD: Makefile,v 1.3 2011/08/13 00:11:17 taca Exp $

DISTNAME=	merb-admin-0.8.8
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/_/-/g}
PKGREVISION=	1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rubygems.org/gems/merb-admin
COMMENT=	Plugin provides easy-to-use interface for managing your data
LICENSE=	mit

DEPENDS+=       ${RUBY_PKGPREFIX}-builder>=2.1:../../textproc/ruby-builder
DEPENDS+=       ${RUBY_PKGPREFIX}-merb-assets>=1.1<2:../../www/merb-assets
DEPENDS+=       ${RUBY_PKGPREFIX}-merb-helpers>=1.1<2:../../www/merb-helpers
DEPENDS+=       ${RUBY_PKGPREFIX}-merb-slices>=1.1<2:../../www/merb-slices

OVERRIDE_GEMSPEC+=	builder>=2.1

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
