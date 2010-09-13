# $NetBSD: Makefile,v 1.3 2010/09/13 14:32:41 taca Exp $

DISTNAME=	merb-helpers-1.1.3
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.merbivore.com/
COMMENT=	Merb plugin that provides various view helpers
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-merb-core>=1.1.3:../../www/merb-core

CONFLICTS+=	merb-helper-[0-9]*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
