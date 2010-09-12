# $NetBSD: Makefile,v 1.2 2010/09/12 02:37:08 taca Exp $

DISTNAME=	merb-builder-0.9.8
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.merbivore.com/
COMMENT=	Merb plugin for ruby-builder XML generation
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-merb-core>=0.9.8:../../www/merb-core
DEPENDS+=	${RUBY_PKGPREFIX}-builder>=2.0.0:../../textproc/ruby-builder

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
