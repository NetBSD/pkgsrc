# $NetBSD: Makefile,v 1.8 2020/03/20 17:22:11 taca Exp $

DISTNAME=	rails-dom-testing-2.0.3
CATEGORIES=	textproc

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/rails/rails-dom-testing
COMMENT=	Ruby module to compare DOMs
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-nokogiri>=1.6.0:../../textproc/ruby-nokogiri

RUBY_RAILS_ACCEPTED=	51 52 60

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
