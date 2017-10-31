# $NetBSD: Makefile,v 1.40 2017/10/31 15:46:33 taca Exp $

DISTNAME=	tzinfo-1.2.4
CATEGORIES=	time

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://tzinfo.github.io/
COMMENT=	Daylight savings aware timezone library
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-thread_safe>=0.1<1:../../misc/ruby-thread_safe

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
