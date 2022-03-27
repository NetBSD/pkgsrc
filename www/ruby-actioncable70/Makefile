# $NetBSD: Makefile,v 1.3 2022/03/27 06:43:12 wiz Exp $

DISTNAME=	actioncable-${RAILS_VERSION}
PKGNAME=	${RUBY_PKGPREFIX}-actioncable${RUBY_RAILS}-${RAILS_VERSION}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Toolkit for building modeling frameworks (part of Rails 7.0)
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIONPACK_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-nio4r>=2.0:../../net/ruby-nio4r
DEPENDS+=	${RUBY_PKGPREFIX}-websocket-driver>=0.6.1:../../www/ruby-websocket-driver

USE_LANGUAGES=	# none

RUBY_RAILS_ACCEPTED=	70
RUBY_RAILS_STRICT_DEP=	yes

RUBY_VERSIONS_INCOMPATIBLE=	26

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
