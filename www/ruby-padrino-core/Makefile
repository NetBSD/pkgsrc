# $NetBSD: Makefile,v 1.1 2013/02/11 14:29:37 taca Exp $

DISTNAME=	padrino-core-${RUBY_PADRINO_VERS}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${RUBY_PADRINO_SITE}
COMMENT=	Padrino framework core
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-sinatra>=1.3.1<1.4:../../www/ruby-sinatra
DEPENDS+=	${RUBY_PKGPREFIX}-http_router>=0.10.2<0.11:../../www/ruby-http_router
DEPENDS+=	${RUBY_PKGPREFIX}-thor>=0.15.2:../../devel/ruby-thor
DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}

CONFLICTS+=	ruby[1-9][0-9][0-9]-padrino-core-[0-9]*

RUBY_RAILS_SUPPORTED=	32

OVERRIDE_GEMSPEC=	thor>=0.15.2

.include "../../www/ruby-padrino/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
