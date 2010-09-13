# $NetBSD: Makefile,v 1.3 2010/09/13 14:32:42 taca Exp $

DISTNAME=	merb-param-protection-1.1.3
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.merbivore.com/
COMMENT=	Merb plugin supplying methods to filter parameters
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-merb-core>=1.1.3:../../www/merb-core

CONFLICTS+=	merb-param-protection-[0-9]*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
