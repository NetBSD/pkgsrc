# $NetBSD: Makefile,v 1.4 2010/09/12 03:22:00 taca Exp $

DISTNAME=	merbful_authentication-0.9.3
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/merbful-auth/
COMMENT=	RESTful authentication plugin for Merb
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-merb-core>=0.9.2:../../www/merb-core
DEPENDS+=	${RUBY_PKGPREFIX}-merb-gen>=0.9.2:../../www/merb-gen

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
