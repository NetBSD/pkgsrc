# $NetBSD: Makefile,v 1.10 2017/03/11 15:12:34 taca Exp $

DISTNAME=	tzinfo-data-1.2017.1
CATEGORIES=	time

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tzinfo.github.io/
COMMENT=	Daylight-savings-aware timezone library data
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-tzinfo>=1.0.0:../../time/ruby-tzinfo

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
