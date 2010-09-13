# $NetBSD: Makefile,v 1.5 2010/09/13 14:49:54 taca Exp $

DISTNAME=	ramaze-2010.06.18
PKGREVISION=	1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ramaze.net/
COMMENT=	Ruby lightweight, modular, web application framework
LICENSE=	ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-rack>=0.2.0:../../www/ruby-rack
DEPENDS+=	${RUBY_PKGPREFIX}-innate>=2010.03:../../www/ruby-innate

CONFLICTS+=	ruby[1-9][0-9]-ramaze-[0-9]* ramaze-[0-9]*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
