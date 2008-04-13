# $NetBSD: Makefile,v 1.2 2008/04/13 06:58:03 jlam Exp $

DISTNAME=	merb_sequel-0.9.2
PKGNAME=	${DISTNAME:S/_/-/g}
PKGREVISION=	1
CATEGORIES=	databases www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.merbivore.com/
COMMENT=	Merb plugin for the Sequel ORM

DEPENDS+=	merb-core>=0.9.2:../../www/merb-core
DEPENDS+=	${RUBY_PKGPREFIX}-sequel>=1.4.0:../../databases/ruby-sequel

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
