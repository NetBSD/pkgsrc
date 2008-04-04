# $NetBSD: Makefile,v 1.1.1.1 2008/04/04 15:24:08 jlam Exp $

DISTNAME=	merb-haml-0.9.2
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.merbivore.com/
COMMENT=	Merb plugin that provides HAML template support

DEPENDS+=	merb-core>=0.9.2:../../www/merb-core
DEPENDS+=	${RUBY_PKGPREFIX}-haml>=1.8.2:../../textproc/ruby-haml

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
