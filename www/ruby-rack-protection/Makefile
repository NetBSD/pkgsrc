# $NetBSD: Makefile,v 1.12 2018/01/08 22:09:48 taca Exp $

DISTNAME=	rack-protection-2.0.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rkh/rack-protection
COMMENT=	Protection for against typical web attacks for Rack application
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack>=2.0:../../www/ruby-rack

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
