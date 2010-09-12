# $NetBSD: Makefile,v 1.3 2010/09/12 02:51:38 taca Exp $

DISTNAME=	merb_sequel-1.1.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	databases www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/pk/merb_sequel
COMMENT=	Merb plugin for the Sequel ORM
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-merb-core>=1.1.0:../../www/merb-core
DEPENDS+=	${RUBY_PKGPREFIX}-sequel>=2.7.0:../../databases/ruby-sequel

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
