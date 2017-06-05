# $NetBSD: Makefile,v 1.9 2017/06/05 03:29:38 taca Exp $

DISTNAME=	rack-protection-2.0.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/rkh/rack-protection
COMMENT=	Protection for against typical web attacks for Rack application
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack>=2.0:../../www/ruby-rack

RUBY_VERSIONS_ACCEPTED=	23 22

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
