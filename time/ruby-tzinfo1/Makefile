# $NetBSD: Makefile,v 1.2 2020/03/20 16:09:10 taca Exp $

DISTNAME=	tzinfo-${VERS}
PKGNAME=	${RUBY_PKGPREFIX}-tzinfo1-${VERS}
CATEGORIES=	time

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	https://tzinfo.github.io/
COMMENT=	Daylight savings aware timezone library
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-thread_safe>=0.1<1:../../misc/ruby-thread_safe

VERS=		1.2.6
USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
