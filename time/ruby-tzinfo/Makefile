# $NetBSD: Makefile,v 1.42 2018/02/28 15:10:01 taca Exp $

DISTNAME=	tzinfo-1.2.5
CATEGORIES=	time

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	https://tzinfo.github.io/
COMMENT=	Daylight savings aware timezone library
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-thread_safe>=0.1<1:../../misc/ruby-thread_safe

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
