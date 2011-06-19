# $NetBSD: Makefile,v 1.4 2011/06/19 08:54:18 taca Exp $

DISTNAME=	merb_datamapper-1.1.3
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	databases www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/merb/merb_datamapper
COMMENT=	Merb plugin for the DataMapper ORM
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-dm-core>=1.0:../../databases/ruby-dm-core
DEPENDS+=	${RUBY_PKGPREFIX}-dm-migrations>=1.0:../../databases/ruby-dm-migrations
DEPENDS+=	${RUBY_PKGPREFIX}-merb-core>=1.1<2:../../www/merb-core

CONFLICTS+=	merb-datamapper-[0-9]*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
