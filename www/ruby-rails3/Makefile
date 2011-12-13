# $NetBSD: Makefile,v 1.6 2011/12/13 16:03:09 taca Exp $

DISTNAME=	rails-${RUBY_RAILS_VERSION}
CATEGORIES=	www

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Full-stack web application framework
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}
DEPENDS+=	${RUBY_ACTIONPACK_DEPENDS}
DEPENDS+=	${RUBY_ACTIVERECORD_DEPENDS}
DEPENDS+=	${RUBY_ACTIVERESOURCE_DEPENDS}
DEPENDS+=	${RUBY_ACTIONMAILER_DEPENDS}
DEPENDS+=	${RUBY_RAILTIES_DEPENDS}
DEPENDS+=       ${RUBY_PKGPREFIX}-bundler>=1.0.0<2:../../misc/ruby-bundler

CONFLICTS+=	ruby[1-9][0-9]-rails-[0-9]*

RUBY_RAILS_SUPPORTED=	3
REPLACE_RUBY=		bin/rails

post-build:
	${MKDIR} ${RUBYGEM_INSTALL_ROOT}${PREFIX}/${GEM_LIBDIR}/lib

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
