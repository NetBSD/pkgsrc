# $NetBSD: Makefile,v 1.2 2017/06/04 14:46:29 taca Exp $

DISTNAME=	actionpack-${RUBY_RAILS_VERSION}
PKGREVISION=	1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Toolkit for building modeling frameworks (part of Rails 4.2)
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIONVIEW_DEPENDS}
DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-rack16>=1.6:../../www/ruby-rack16
DEPENDS+=	${RUBY_PKGPREFIX}-rack-test>=0.6.2<0.7:../../www/ruby-rack-test
DEPENDS+=	${RUBY_PKGPREFIX}-rails-dom-testing>=1.0.5:../../textproc/ruby-rails-dom-testing
DEPENDS+=	${RUBY_PKGPREFIX}-rails-html-sanitizer>=1.0.2:../../www/ruby-rails-html-sanitizer

RUBY_RAILS_SUPPORTED=	42
RUBY_RAILS_STRICT_DEP=	yes

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
