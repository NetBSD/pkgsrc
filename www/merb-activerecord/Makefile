# $NetBSD: Makefile,v 1.1.1.1 2008/04/04 15:23:15 jlam Exp $

DISTNAME=	merb_activerecord-0.9.2
PKGNAME=	${DISTNAME:S/_/-/g}
CATEGORIES=	databases www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.merbivore.com/
COMMENT=	Merb plugin for the ActiveRecord ORM

DEPENDS+=	merb-core>=0.9.2:../../www/merb-core
DEPENDS+=	${RUBY_PKGPREFIX}-activerecord>=1.2.6:../../databases/ruby-activerecord

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
