# $NetBSD: Makefile,v 1.12 2021/05/21 21:06:19 nia Exp $

DISTNAME=	ramaze-2012.12.08
PKGREVISION=	1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ramaze.net/
COMMENT=	Ruby lightweight, modular, web application framework
LICENSE=	ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-innate>=2012.12:../../www/ruby-innate

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} ramaze ramaze${RUBY_SUFFIX}

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
