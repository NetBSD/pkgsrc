# $NetBSD: Makefile,v 1.2 2010/09/12 02:34:34 taca Exp $

DISTNAME=	merb_activerecord-1.0.0.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	databases www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.merbivore.com/
COMMENT=	Merb plugin for the ActiveRecord ORM
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-merb-core>=0.9.2:../../www/merb-core

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
