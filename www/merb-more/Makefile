# $NetBSD: Makefile,v 1.3 2010/09/13 14:32:42 taca Exp $

DISTNAME=	merb-more-1.0.15
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.merbivore.com/
COMMENT=	Merb classes and framework for "full stack" functionality
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-merb-core>=1.0.15:../../www/merb-core
DEPENDS+=	${RUBY_PKGPREFIX}-merb-action-args>=1.0.15:../../www/merb-action-args
DEPENDS+=	${RUBY_PKGPREFIX}-merb-assets>=1.0.15:../../www/merb-assets
DEPENDS+=	${RUBY_PKGPREFIX}-merb-slices>=1.0.15:../../www/merb-slices
DEPENDS+=	${RUBY_PKGPREFIX}-merb-auth>=1.0.15:../../www/merb-auth
DEPENDS+=	${RUBY_PKGPREFIX}-merb-cache>=1.0.15:../../www/merb-cache
DEPENDS+=	${RUBY_PKGPREFIX}-merb-exceptions>=1.0.15:../../www/merb-exceptions
DEPENDS+=	${RUBY_PKGPREFIX}-merb-gen>=1.0.15:../../www/merb-gen
DEPENDS+=	${RUBY_PKGPREFIX}-merb-haml>=1.0.15:../../www/merb-haml
DEPENDS+=	${RUBY_PKGPREFIX}-merb-helpers>=1.0.15:../../www/merb-helpers
DEPENDS+=	${RUBY_PKGPREFIX}-merb-mailer>=1.0.15:../../www/merb-mailer
DEPENDS+=	${RUBY_PKGPREFIX}-merb-param-protection>=1.0.15:../../www/merb-param-protection

CONFLICTS+=	merb-more-[0-9]*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
