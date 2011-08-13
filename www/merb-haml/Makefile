# $NetBSD: Makefile,v 1.4 2011/08/13 00:19:01 taca Exp $

DISTNAME=	merb-haml-1.1.3
PKGREVISION=	1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.merbivore.com/
COMMENT=	Merb plugin that provides HAML template support
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-merb-core>=1.1.3<1.2:../../www/merb-core
DEPENDS+=	${RUBY_PKGPREFIX}-haml>=2.0.3:../../textproc/ruby-haml

CONFLICTS+=	merb-haml-[0-9]*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
