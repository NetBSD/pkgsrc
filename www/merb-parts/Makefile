# $NetBSD: Makefile,v 1.4 2011/08/13 00:20:59 taca Exp $

DISTNAME=	merb_parts-0.9.14
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.merbivore.com/
COMMENT=	Merb plugin that provides Part Controllers
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-merb-core>=0.9.8:../../www/merb-core

CONFLICTS+=	merb-parts-[0-9]*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
