# $NetBSD: Makefile,v 1.3 2017/06/21 15:42:11 taca Exp $

DISTNAME=	rails-dom-testing-1.0.8
PKGREVISION=	1
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
