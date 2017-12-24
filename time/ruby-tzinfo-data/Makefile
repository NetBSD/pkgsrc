# $NetBSD: Makefile,v 1.13 2017/12/24 10:17:13 wiz Exp $

DISTNAME=	tzinfo-data-1.2017.3
CATEGORIES=	time

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://tzinfo.github.io/
COMMENT=	Daylight-savings-aware timezone library data
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-tzinfo>=1.0.0:../../time/ruby-tzinfo

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
