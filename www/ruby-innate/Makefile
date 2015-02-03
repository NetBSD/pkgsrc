# $NetBSD: Makefile,v 1.10 2015/02/03 03:04:23 taca Exp $

DISTNAME=	innate-2013.02.21
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/manveru/innate
COMMENT=	Powerful web-framework wrapper for Rack
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack15>=1.5.2<1.6:../../www/ruby-rack15

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
