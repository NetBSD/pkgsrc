# $NetBSD: Makefile,v 1.5 2011/05/30 13:08:15 hiramatsu Exp $

DISTNAME=	rails-${RUBY_RAILS3_VERSION}
CATEGORIES=	www

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Full-stack web application framework
LICENSE=	mit

RUBY_RAILS=	3

DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}
DEPENDS+=	${RUBY_ACTIONPACK_DEPENDS}
DEPENDS+=	${RUBY_ACTIVERECORD_DEPENDS}
DEPENDS+=	${RUBY_ACTIVERESOURCE_DEPENDS}
DEPENDS+=	${RUBY_ACTIONMAILER_DEPENDS}
DEPENDS+=	${RUBY_RAILTIES_DEPENDS}
DEPENDS+=       ${RUBY_PKGPREFIX}-bundler>=1.0.0<2:../../misc/ruby-bundler

CONFLICTS+=	ruby[1-9][0-9]-rails-[0-9]*

REPLACE_RUBY=	bin/rails

post-build:
	${MKDIR} ${RUBYGEM_INSTALL_ROOT}${PREFIX}/${GEM_LIBDIR}/lib

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
