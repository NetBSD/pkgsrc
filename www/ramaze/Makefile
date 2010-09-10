# $NetBSD: Makefile,v 1.4 2010/09/10 12:42:12 taca Exp $

DISTNAME=	ramaze-2010.06.18
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ramaze.net/
COMMENT=	Ruby lightweight, modular, web application framework
LICENSE=	ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-rack>=0.2.0:../../www/ruby-rack
DEPENDS+=	${RUBY_PKGPREFIX}-innate>=2010.03:../../www/ruby-innate

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
