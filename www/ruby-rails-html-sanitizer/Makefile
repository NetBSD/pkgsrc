# $NetBSD: Makefile,v 1.3 2020/03/20 17:54:27 taca Exp $

DISTNAME=	rails-html-sanitizer-1.3.0
CATEGORIES=	www

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/rails/rails-html-sanitizer
COMMENT=	HTML sanitizer for Rails applications
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-loofah>=2.2.0:../../www/ruby-loofah

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
