# $NetBSD: Makefile,v 1.3 2010/09/13 14:32:40 taca Exp $

DISTNAME=	merb_activerecord-1.0.0.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	databases www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.merbivore.com/
COMMENT=	Merb plugin for the ActiveRecord ORM
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-merb-core>=0.9.2:../../www/merb-core

CONFLICTS+=	merb-activerecord-[0-9]*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
