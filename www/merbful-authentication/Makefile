# $NetBSD: Makefile,v 1.1.1.1 2008/04/04 15:25:21 jlam Exp $

DISTNAME=	merbful_authentication-0.9.2
PKGNAME=	${DISTNAME:S/_/-/g}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	RESTful authentication plugin for Merb

DEPENDS+=	merb-core>=0.9.2:../../www/merb-core
DEPENDS+=	merb-gen>=0.9.2:../../www/merb-gen

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
