# $NetBSD: Makefile,v 1.16 2020/03/20 16:30:27 taca Exp $

DISTNAME=	sinatra-contrib-2.0.8.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.sinatrarb.com/contrib/
COMMENT=	Collection of useful Sinatra extensions
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-sinatra>=2.0.8.1<2.0.9:../../www/ruby-sinatra
DEPENDS+=	${RUBY_PKGPREFIX}-backports>=2.8.2:../../devel/ruby-backports
DEPENDS+=	${RUBY_PKGPREFIX}-multi_json-[0-9]*:../../textproc/ruby-multi_json

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
