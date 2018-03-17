# $NetBSD: Makefile,v 1.12 2018/03/17 15:59:55 taca Exp $

DISTNAME=	sinatra-contrib-2.0.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.sinatrarb.com/contrib/
COMMENT=	Collection of useful Sinatra extensions
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-sinatra>=2.0.1<3:../../www/ruby-sinatra
DEPENDS+=	${RUBY_PKGPREFIX}-backports>=2.0:../../devel/ruby-backports
DEPENDS+=	${RUBY_PKGPREFIX}-multi_json-[0-9]*:../../textproc/ruby-multi_json

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
