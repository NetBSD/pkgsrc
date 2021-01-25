# $NetBSD: Makefile,v 1.26 2021/01/25 15:11:00 taca Exp $

DISTNAME=	tzinfo-data-1.2021.1
CATEGORIES=	time

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://tzinfo.github.io/
COMMENT=	Daylight-savings-aware timezone library data
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-tzinfo{,1}>=1.0.0:../../time/ruby-tzinfo

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
