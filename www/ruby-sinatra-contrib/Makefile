# $NetBSD: Makefile,v 1.3 2013/08/26 10:19:23 obache Exp $

DISTNAME=	sinatra-contrib-1.4.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/sinatra/sinatra-contrib/
COMMENT=	Collection of useful Sinatra extensions
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-backports>=2.0:../../devel/ruby-backports
DEPENDS+=	${RUBY_PKGPREFIX}-rack-protection-[0-9]*:../../www/ruby-rack-protection
DEPENDS+=	${RUBY_PKGPREFIX}-rack-test-[0-9]*:../../www/ruby-rack-test
DEPENDS+=	${RUBY_PKGPREFIX}-sinatra>=1.4.2<1.5:../../www/ruby-sinatra
DEPENDS+=	${RUBY_PKGPREFIX}-tilt>=1.3<1.4:../../textproc/ruby-tilt
DEPENDS+=	${RUBY_PKGPREFIX}-multi_json-[0-9]*:../../textproc/ruby-multi_json

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
