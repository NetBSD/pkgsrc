# $NetBSD: Makefile,v 1.2 2013/06/16 10:04:08 obache Exp $

DISTNAME=	padrino-core-${RUBY_PADRINO_VERS}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${RUBY_PADRINO_SITE}
COMMENT=	Padrino framework core
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-http_router>=0.11.0<0.12:../../www/ruby-http_router
DEPENDS+=	${RUBY_PKGPREFIX}-rack-protection>=1.5.0:../../www/ruby-rack-protection
DEPENDS+=	${RUBY_PKGPREFIX}-sinatra>=1.4.2<1.5:../../www/ruby-sinatra
DEPENDS+=	${RUBY_PKGPREFIX}-thor>=0.17.0:../../devel/ruby-thor
DEPENDS+=	${RUBY_PKGPREFIX}-tilt>=1.3.7:../../textproc/ruby-tilt

CONFLICTS+=	ruby[1-9][0-9][0-9]-padrino-core-[0-9]*

RUBY_RAILS_SUPPORTED=	32

.include "../../www/ruby-padrino/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
