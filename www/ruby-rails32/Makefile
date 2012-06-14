# $NetBSD: Makefile,v 1.2 2012/06/14 15:12:16 taca Exp $

DISTNAME=	rails-${RUBY_RAILS_VERSION}
CATEGORIES=	www

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Full-stack web application framework, Rails 3.2
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}
DEPENDS+=	${RUBY_ACTIONPACK_DEPENDS}
DEPENDS+=	${RUBY_ACTIVERECORD_DEPENDS}
DEPENDS+=	${RUBY_ACTIVERESOURCE_DEPENDS}
DEPENDS+=	${RUBY_ACTIONMAILER_DEPENDS}
DEPENDS+=	${RUBY_RAILTIES_DEPENDS}
DEPENDS+=       ${RUBY_PKGPREFIX}-bundler>=1.0<2:../../misc/ruby-bundler

CONFLICTS+=	ruby[1-9][0-9]-rails-[0-9]*

RUBY_RAILS_SUPPORTED=	32
RUBY_RAILS_STRICT_DEP=	yes
REPLACE_RUBY=		bin/rails

post-build:
	${MKDIR} ${RUBYGEM_INSTALL_ROOT}${PREFIX}/${GEM_LIBDIR}/lib

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
