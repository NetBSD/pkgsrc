# $NetBSD: Makefile,v 1.11 2017/07/30 22:32:28 wiz Exp $

DISTNAME=	rack-protection-2.0.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rkh/rack-protection
COMMENT=	Protection for against typical web attacks for Rack application
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack>=2.0:../../www/ruby-rack

RUBY_VERSIONS_ACCEPTED=	23 22 24

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
