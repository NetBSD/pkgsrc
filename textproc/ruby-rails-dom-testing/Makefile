# $NetBSD: Makefile,v 1.12 2023/08/05 12:19:03 taca Exp $

DISTNAME=	rails-dom-testing-2.2.0
CATEGORIES=	textproc

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/rails/rails-dom-testing
COMMENT=	Ruby module to compare DOMs
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-nokogiri>=1.6.0:../../textproc/ruby-nokogiri

USE_LANGUAGES=	# none

RUBY_RAILS_ACCEPTED=	# empty

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
