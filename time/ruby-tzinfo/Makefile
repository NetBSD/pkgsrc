# $NetBSD: Makefile,v 1.39 2017/04/15 15:11:23 taca Exp $

DISTNAME=	tzinfo-1.2.3
CATEGORIES=	time

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://tzinfo.github.io/
COMMENT=	Daylight savings aware timezone library
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-thread_safe>=0.1<1:../../misc/ruby-thread_safe

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
