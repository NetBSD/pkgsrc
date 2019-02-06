# $NetBSD: Makefile,v 1.14 2019/02/06 14:55:55 taca Exp $

DISTNAME=	sinatra-contrib-2.0.5
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.sinatrarb.com/contrib/
COMMENT=	Collection of useful Sinatra extensions
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-sinatra>=2.0.4<2.1:../../www/ruby-sinatra
DEPENDS+=	${RUBY_PKGPREFIX}-backports>=2.8.2:../../devel/ruby-backports
DEPENDS+=	${RUBY_PKGPREFIX}-multi_json-[0-9]*:../../textproc/ruby-multi_json
DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}

RUBY_RAILS_ACCEPTED=	42

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
