# $NetBSD: Makefile,v 1.4 2010/09/13 14:32:42 taca Exp $

DISTNAME=	merb_sequel-1.1.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	databases www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/pk/merb_sequel
COMMENT=	Merb plugin for the Sequel ORM
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-merb-core>=1.1.0:../../www/merb-core
DEPENDS+=	${RUBY_PKGPREFIX}-sequel>=2.7.0:../../databases/ruby-sequel

CONFLICTS+=	merb-sequel-[0-9]*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
