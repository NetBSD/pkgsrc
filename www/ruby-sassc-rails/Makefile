# $NetBSD: Makefile,v 1.2 2020/03/20 20:44:15 joerg Exp $

DISTNAME=	sassc-rails-2.1.2
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sass/sassc-rails
COMMENT=	Integrate SassC-Ruby into Rails
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-sassc>=2.0:../../www/ruby-sassc
DEPENDS+=	${RUBY_PKGPREFIX}-tilt>=0:../../textproc/ruby-tilt
DEPENDS+=	${RUBY_PKGPREFIX}-sprockets-rails>=0:../../misc/ruby-sprockets-rails
DEPENDS+=	${RUBY_RAILTIES_DEPENDS}

USE_LANGUAGES=	# none

RUBY_VERSIONS_INCOMPATIBLE=	24
RUBY_RAILS_ACCEPTED=	# yes

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
