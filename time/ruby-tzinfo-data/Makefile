# $NetBSD: Makefile,v 1.16 2018/05/21 16:00:16 taca Exp $

DISTNAME=	tzinfo-data-1.2018.5
CATEGORIES=	time

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://tzinfo.github.io/
COMMENT=	Daylight-savings-aware timezone library data
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-tzinfo>=1.0.0:../../time/ruby-tzinfo

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
