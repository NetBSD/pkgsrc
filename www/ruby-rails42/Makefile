# $NetBSD: Makefile,v 1.7.2.1 2019/05/05 15:49:21 bsiegert Exp $

DISTNAME=	rails-${RAILS_VERSION}
PKGNAME=	${RUBY_PKGPREFIX}-rails${RUBY_RAILS}-${RAILS_VERSION}
CATEGORIES=	www

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Full-stack web application framework, Rails 4.2
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIONMAILER_DEPENDS}
DEPENDS+=	${RUBY_ACTIONPACK_DEPENDS}
DEPENDS+=	${RUBY_ACTIONVIEW_DEPENDS}
DEPENDS+=	${RUBY_ACTIVEJOB_DEPENDS}
DEPENDS+=	${RUBY_ACTIVEMODEL_DEPENDS}
DEPENDS+=	${RUBY_ACTIVERECORD_DEPENDS}
DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}
DEPENDS+=	${RUBY_RAILTIES_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-sprockets-rails-[0-9]*:../../misc/ruby-sprockets-rails

CONFLICTS+=	ruby[1-9][0-9]-rails-[0-9]*

RUBY_RAILS_ACCEPTED=	42
RUBY_RAILS_STRICT_DEP=	yes

.include "../../lang/ruby/gem.mk"
.if ${RUBY_VER} != 26
DEPENDS+=	${RUBY_PKGPREFIX}-bundler1>=1.3.0<2:../../misc/ruby-bundler1
.endif
.include "../../mk/bsd.pkg.mk"
