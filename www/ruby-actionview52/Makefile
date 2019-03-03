# $NetBSD: Makefile,v 1.1 2019/03/03 14:50:27 taca Exp $

DISTNAME=	actionview-${RAILS_VERSION}
PKGNAME=	${RUBY_PKGPREFIX}-actionview${RUBY_RAILS}-${RAILS_VERSION}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Rendering framework putting the V in MVC (part of Rails 5.2)
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-builder>=3.1:../../textproc/ruby-builder
DEPENDS+=	${RUBY_PKGPREFIX}-erubi>=1.4:../../textproc/ruby-erubi
DEPENDS+=	${RUBY_PKGPREFIX}-rails-dom-testing>=2.0:../../textproc/ruby-rails-dom-testing
DEPENDS+=	${RUBY_PKGPREFIX}-rails-html-sanitizer>=1.0.3:../../www/ruby-rails-html-sanitizer

USE_LANGUAGES=	# none

RUBY_RAILS_ACCEPTED=	52
RUBY_RAILS_STRICT_DEP=	yes

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
