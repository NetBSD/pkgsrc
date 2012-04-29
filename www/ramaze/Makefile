# $NetBSD: Makefile,v 1.10 2012/04/29 16:09:34 taca Exp $

DISTNAME=	ramaze-2012.04.14
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ramaze.net/
COMMENT=	Ruby lightweight, modular, web application framework
LICENSE=	ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-innate>=2012.3:../../www/ruby-innate

CONFLICTS+=	ruby[1-9][0-9]-ramaze-[0-9]* ramaze-[0-9]*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
