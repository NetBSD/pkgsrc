# $NetBSD: Makefile,v 1.10 2017/06/18 13:48:54 taca Exp $

DISTNAME=	sinatra-contrib-2.0.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sinatra/sinatra-contrib/
COMMENT=	Collection of useful Sinatra extensions
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-sinatra>=2.0<3:../../www/ruby-sinatra
DEPENDS+=	${RUBY_PKGPREFIX}-backports>=2.0:../../devel/ruby-backports
DEPENDS+=	${RUBY_PKGPREFIX}-multi_json-[0-9]*:../../textproc/ruby-multi_json

RUBY_VERSIONS_ACCEPTED=	23 22 24

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
