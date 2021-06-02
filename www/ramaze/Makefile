# $NetBSD: Makefile,v 1.13 2021/06/02 15:52:04 taca Exp $

DISTNAME=	ramaze-2012.12.08
PKGREVISION=	1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ramaze.net/
COMMENT=	Ruby lightweight, modular, web application framework
LICENSE=	ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-innate>=2012.12:../../www/ruby-innate

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
