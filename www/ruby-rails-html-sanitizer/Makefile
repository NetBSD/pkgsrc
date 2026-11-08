# $NetBSD: Makefile,v 1.13 2026/11/08 14:20:36 taca Exp $

DISTNAME=	rails-html-sanitizer-1.7.2
CATEGORIES=	www

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/rails/rails-html-sanitizer
COMMENT=	HTML sanitizer for Rails applications
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-loofah>=2.25.2<3:../../www/ruby-loofah

USE_LANGUAGES=	# empty

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
