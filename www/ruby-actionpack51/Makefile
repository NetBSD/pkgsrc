# $NetBSD: Makefile,v 1.2 2018/10/09 17:05:56 taca Exp $

DISTNAME=	actionpack-${RAILS_VERSION}
PKGNAME=	${RUBY_PKGPREFIX}-actionpack${RUBY_RAILS}-${RAILS_VERSION}
PKGREVISION=	1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Toolkit for building modeling frameworks (part of Rails 5.2)
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIONVIEW_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-rack>=2.0:../../www/ruby-rack
DEPENDS+=	${RUBY_PKGPREFIX}-rack-test>=0.6.3:../../www/ruby-rack-test
# ruby-actionview already depends them.
#DEPENDS+=	${RUBY_PKGPREFIX}-rails-dom-testing1>=2.0:../../textproc/ruby-rails-dom-testing
#DEPENDS+=	${RUBY_PKGPREFIX}-rails-html-sanitizer>=1.0.2:../../www/ruby-rails-html-sanitizer

RUBY_RAILS_ACCEPTED=	51
RUBY_RAILS_STRICT_DEP=	yes

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
