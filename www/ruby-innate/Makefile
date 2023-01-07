# $NetBSD: Makefile,v 1.15 2023/01/07 05:13:06 taca Exp $

DISTNAME=	innate-2023.01.06
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Ramaze/innate
COMMENT=	Powerful web-framework wrapper for Rack
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack>=3.0<4:../../www/ruby-rack

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
