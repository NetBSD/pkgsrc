# $NetBSD: Makefile,v 1.41 2017/12/24 10:16:53 wiz Exp $

DISTNAME=	tzinfo-1.2.4
CATEGORIES=	time

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	https://tzinfo.github.io/
COMMENT=	Daylight savings aware timezone library
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-thread_safe>=0.1<1:../../misc/ruby-thread_safe

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
