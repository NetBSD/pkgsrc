# $NetBSD: Makefile,v 1.4 2011/08/13 00:11:40 taca Exp $

DISTNAME=	merb-assets-1.1.3
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.merbivore.com/
COMMENT=	Merb plugin that provides helpers for assets and asset bundling
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-merb-core>=1.1.3<1.2:../../www/merb-core

CONFLICTS+=	merb-assets-[0-9]*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
