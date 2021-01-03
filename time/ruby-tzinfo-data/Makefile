# $NetBSD: Makefile,v 1.25 2021/01/03 08:22:22 taca Exp $

DISTNAME=	tzinfo-data-1.2020.6
CATEGORIES=	time

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://tzinfo.github.io/
COMMENT=	Daylight-savings-aware timezone library data
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-tzinfo{,1}>=1.0.0:../../time/ruby-tzinfo

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
