# $NetBSD: Makefile,v 1.2 2010/09/12 02:42:28 taca Exp $

DISTNAME=	merb-haml-1.1.3
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.merbivore.com/
COMMENT=	Merb plugin that provides HAML template support
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-merb-core>=1.1.3:../../www/merb-core
DEPENDS+=	${RUBY_PKGPREFIX}-haml>=2.0.3:../../textproc/ruby-haml

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
