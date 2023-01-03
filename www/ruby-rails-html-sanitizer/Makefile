# $NetBSD: Makefile,v 1.6 2023/01/03 15:19:13 taca Exp $

DISTNAME=	rails-html-sanitizer-1.4.4
CATEGORIES=	www

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/rails/rails-html-sanitizer
COMMENT=	HTML sanitizer for Rails applications
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-loofah>=2.19<3:../../www/ruby-loofah

USE_LANGUAGES=	# empty

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
