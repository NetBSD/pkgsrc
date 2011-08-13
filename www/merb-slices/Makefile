# $NetBSD: Makefile,v 1.3 2011/08/13 00:21:37 taca Exp $

DISTNAME=	merb-slices-1.1.3
PKGREVISION=	2
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.merbivore.com/
COMMENT=	Merb plugin that supports reusable application 'slices'
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-merb-core>=1.1.3<1.2:../../www/merb-core

CONFLICTS+=	ruby[1-9][0-9]-merb-slices-[0-9]*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
