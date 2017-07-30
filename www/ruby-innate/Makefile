# $NetBSD: Makefile,v 1.13 2017/07/30 22:32:27 wiz Exp $

DISTNAME=	innate-2015.10.28
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/manveru/innate
COMMENT=	Powerful web-framework wrapper for Rack
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack16>=1.6.4<1.7:../../www/ruby-rack16

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
