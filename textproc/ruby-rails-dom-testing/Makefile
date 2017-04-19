# $NetBSD: Makefile,v 1.1 2017/04/19 06:12:41 minskim Exp $

DISTNAME=	rails-dom-testing-1.0.8
CATEGORIES=	textproc

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/rails/rails-dom-testing
COMMENT=	Ruby module to compare DOMs
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-activesupport>=4.2.0<5.0:../../devel/ruby-activesupport42
DEPENDS+=	${RUBY_PKGPREFIX}-nokogiri>=1.6.0:../../textproc/ruby-nokogiri
DEPENDS+=	${RUBY_PKGPREFIX}-rails-deprecated_sanitizer>=1.0.1:../../www/ruby-rails-deprecated_sanitizer

OVERRIDE_GEMSPEC+=	nokogiri>=1.6.0

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
