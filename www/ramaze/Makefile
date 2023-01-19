# $NetBSD: Makefile,v 1.14 2023/01/19 15:17:29 taca Exp $

DISTNAME=	ramaze-2023.01.06
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ramaze.net/
COMMENT=	Ruby lightweight, modular, web application framework
LICENSE=	ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-innate>=2012.12:../../www/ruby-innate

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
