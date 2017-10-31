# $NetBSD: Makefile,v 1.12 2017/10/31 15:47:50 taca Exp $

DISTNAME=	tzinfo-data-1.2017.3
CATEGORIES=	time

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tzinfo.github.io/
COMMENT=	Daylight-savings-aware timezone library data
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-tzinfo>=1.0.0:../../time/ruby-tzinfo

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
