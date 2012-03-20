# $NetBSD: Makefile,v 1.9 2012/03/20 13:53:35 taca Exp $

DISTNAME=	ramaze-2012.03.07
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ramaze.net/
COMMENT=	Ruby lightweight, modular, web application framework
LICENSE=	ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-innate>=2012.3:../../www/ruby-innate

CONFLICTS+=	ruby[1-9][0-9]-ramaze-[0-9]* ramaze-[0-9]*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
