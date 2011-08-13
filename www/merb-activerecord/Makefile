# $NetBSD: Makefile,v 1.4 2011/08/13 00:10:13 taca Exp $

DISTNAME=	merb_activerecord-1.0.0.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/_/-/g}
PKGREVISION=	1
CATEGORIES=	databases www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.merbivore.com/
COMMENT=	Merb plugin for the ActiveRecord ORM
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-merb-core>=0.9.9:../../www/merb-core

CONFLICTS+=	merb-activerecord-[0-9]*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
