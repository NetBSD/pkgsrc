# $NetBSD: Makefile,v 1.5 2023/09/10 14:19:01 taca Exp $

DISTNAME=	actionview-${RAILS_VERSION}
PKGNAME=	${RUBY_PKGPREFIX}-actionview${RUBY_RAILS}-${RAILS_VERSION}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Rendering framework putting the V in MVC (part of Rails 7.0)
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-builder>=3.1<4:../../textproc/ruby-builder
DEPENDS+=	${RUBY_PKGPREFIX}-erubi>=1.4<2:../../textproc/ruby-erubi
DEPENDS+=	${RUBY_PKGPREFIX}-rails-dom-testing>=2.0<3:../../textproc/ruby-rails-dom-testing
DEPENDS+=	${RUBY_PKGPREFIX}-rails-html-sanitizer>=1.2.0<2:../../www/ruby-rails-html-sanitizer

USE_LANGUAGES=	# none

RUBY_RAILS_ACCEPTED=	70
RUBY_RAILS_STRICT_DEP=	yes

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
