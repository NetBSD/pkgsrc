# $NetBSD: Makefile,v 1.1.1.1 2008/04/04 15:23:53 jlam Exp $

DISTNAME=	merb_datamapper-0.9.2
PKGNAME=	${DISTNAME:S/_/-/g}
CATEGORIES=	databases www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.merbivore.com/
COMMENT=	Merb plugin for the DataMapper ORM

DEPENDS+=	merb-core>=0.9.2:../../www/merb-core
DEPENDS+=	${RUBY_PKGPREFIX}-datamapper>=0.2.3:../../databases/ruby-datamapper

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
