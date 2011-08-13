# $NetBSD: Makefile,v 1.4 2011/08/13 00:17:40 taca Exp $

DISTNAME=	merb-cache-1.1.3
PKGREVISION=	1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.merbivore.com/
COMMENT=	Merb plugin that provides caching (page, action, fragment, object)
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-merb-core>=1.1.3<1.2:../../www/merb-core

CONFLICTS+=	merb-cache-[0-9]*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
