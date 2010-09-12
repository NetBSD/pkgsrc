# $NetBSD: Makefile,v 1.1.1.1 2010/09/12 04:23:56 taca Exp $

DISTNAME=	rails-3.0.0
CATEGORIES=	www

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Full-stack web application framework
LICENSE=	mit

DEPENDS+=       ${RUBY_PKGPREFIX}-activesupport>=3.0.0:../../devel/ruby-activesupport3
DEPENDS+=       ${RUBY_PKGPREFIX}-actionpack>=3.0.0:../../www/ruby-actionpack3
DEPENDS+=       ${RUBY_PKGPREFIX}-activerecord>=3.0.0:../../databases/ruby-activerecord3
DEPENDS+=       ${RUBY_PKGPREFIX}-activeresource>=3.0.0:../../www/ruby-activeresource3
DEPENDS+=       ${RUBY_PKGPREFIX}-actionmailer>=3.0.0:../../mail/ruby-actionmailer3
DEPENDS+=       ${RUBY_PKGPREFIX}-railties>=3.0.0:../../devel/ruby-railties
DEPENDS+=       ${RUBY_PKGPREFIX}-bundler>=1.0.0:../../misc/ruby-bundler

CONFLICTS+=	ruby[1-9][0-9]-rails-[0-9]*

REPLACE_RUBY=	bin/rails

post-build:
	${MKDIR} ${RUBYGEM_INSTALL_ROOT}${PREFIX}/${GEM_LIBDIR}/lib

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
