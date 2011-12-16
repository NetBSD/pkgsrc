# $NetBSD: Makefile,v 1.8 2011/12/16 13:21:50 taca Exp $

DISTNAME=	ramaze-2011.10.23
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ramaze.net/
COMMENT=	Ruby lightweight, modular, web application framework
LICENSE=	ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-innate>=2010.03:../../www/ruby-innate

CONFLICTS+=	ruby[1-9][0-9]-ramaze-[0-9]* ramaze-[0-9]*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
