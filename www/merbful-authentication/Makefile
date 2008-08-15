# $NetBSD: Makefile,v 1.3 2008/08/15 16:08:00 taca Exp $

DISTNAME=	merbful_authentication-0.9.3
PKGNAME=	${DISTNAME:S/_/-/g}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/merbful-auth/
COMMENT=	RESTful authentication plugin for Merb

DEPENDS+=	merb-core>=0.9.2:../../www/merb-core
DEPENDS+=	merb-gen>=0.9.2:../../www/merb-gen

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
