# $NetBSD: Makefile,v 1.4 2011/08/13 00:08:58 taca Exp $

DISTNAME=	merb-1.1.3
PKGREVISION=	1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.merbivore.com/
COMMENT=	Mongrel + Erb -- pocket rocket web framework
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-merb-action-args>=1.1.3<1.2:../../www/merb-action-args
DEPENDS+=	${RUBY_PKGPREFIX}-merb-assets>=1.1.3<1.2:../../www/merb-assets
DEPENDS+=	${RUBY_PKGPREFIX}-merb-auth>=1.1<1.2:../../www/merb-auth
DEPENDS+=	${RUBY_PKGPREFIX}-merb-cache>=1.1.3<1.2:../../www/merb-cache
DEPENDS+=	${RUBY_PKGPREFIX}-merb-exceptions>=1.1.3<1.2:../../www/merb-exceptions
DEPENDS+=	${RUBY_PKGPREFIX}-merb-gen>=1.1.3<1.2:../../www/merb-gen
DEPENDS+=	${RUBY_PKGPREFIX}-merb-haml>=1.1.3<1.2:../../www/merb-haml
DEPENDS+=	${RUBY_PKGPREFIX}-merb-helpers>=1.1.3<1.2:../../www/merb-helpers
DEPENDS+=	${RUBY_PKGPREFIX}-merb-mailer>=1.1.3<1.2:../../www/merb-mailer
DEPENDS+=	${RUBY_PKGPREFIX}-merb-param-protection>=1.1.3<1.2:../../www/merb-param-protection
DEPENDS+=	${RUBY_PKGPREFIX}-merb-slices>=1.1.3<1.2:../../www/merb-slices
DEPENDS+=	${RUBY_PKGPREFIX}-merb-datamapper>=1.1<2:../../www/merb-datamapper
DEPENDS+=	${RUBY_PKGPREFIX}-datamapper>=0.10.0:../../databases/ruby-datamapper
DEPENDS+=	${RUBY_PKGPREFIX}-do_sqlite3>=0.10.0:../../databases/ruby-do_sqlite3
DEPENDS+=	${RUBY_PKGPREFIX}-rspec>=0:../../devel/ruby-rspec

CONFLICTS+=	merb-[0-9]*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
