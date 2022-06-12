# $NetBSD: Makefile,v 1.5 2022/06/12 12:20:11 taca Exp $

DISTNAME=	rails-html-sanitizer-1.4.3
CATEGORIES=	www

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/rails/rails-html-sanitizer
COMMENT=	HTML sanitizer for Rails applications
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-loofah>=2.3<3:../../www/ruby-loofah

USE_LANGUAGES=	# empty

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
