# $NetBSD: Makefile,v 1.1.1.1 2008/04/04 15:25:00 jlam Exp $

DISTNAME=	merb_sequel-0.9.2
PKGNAME=	${DISTNAME:S/_/-/g}
CATEGORIES=	databases www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.merbivore.com/
COMMENT=	Merb plugin for the Sequel ORM

DEPENDS+=	merb-core>=0.9.2:../../www/merb-core
DEPENDS+=	${RUBY_PKGPREFIX}-sequel>=1.0.0:../../databases/ruby-sequel
DEPENDS+=	${RUBY_PKGPREFIX}-sequel-model>=0.3.3:../../databases/ruby-sequel-model

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
