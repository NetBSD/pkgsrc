# $NetBSD: Makefile,v 1.5 2010/09/13 14:39:31 taca Exp $

DISTNAME=	merbful_authentication-0.9.3
PKGREVISION=	1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/merbful-auth/
COMMENT=	RESTful authentication plugin for Merb
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-merb-core>=0.9.2:../../www/merb-core
DEPENDS+=	${RUBY_PKGPREFIX}-merb-gen>=0.9.2:../../www/merb-gen

CONFLICTS+=	ruby[1-9][0-9]-merbful-authentication-[0-9]* \
		merbful-authentication-[0-9]*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
