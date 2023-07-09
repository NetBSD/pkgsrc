# $NetBSD: Makefile,v 1.11 2023/07/09 02:47:18 taca Exp $

DISTNAME=	rails-dom-testing-2.1.1
CATEGORIES=	textproc

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/rails/rails-dom-testing
COMMENT=	Ruby module to compare DOMs
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-nokogiri>=1.6.0:../../textproc/ruby-nokogiri

RUBY_RAILS_ACCEPTED=	# empty

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
