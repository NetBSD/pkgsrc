# $NetBSD: Makefile,v 1.1 2018/03/13 16:20:12 taca Exp $

DISTNAME=	rails-dom-testing-1.0.9
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/-testing/-testing1/}
CATEGORIES=	textproc

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/rails/rails-dom-testing
COMMENT=	Ruby module to compare DOMs
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-nokogiri>=1.6.0:../../textproc/ruby-nokogiri
DEPENDS+=	${RUBY_PKGPREFIX}-rails-deprecated_sanitizer>=1.0.1:../../www/ruby-rails-deprecated_sanitizer

OVERRIDE_GEMSPEC+=	nokogiri>=1.6.0
RUBY_RAILS_SUPPORTED=	42

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
