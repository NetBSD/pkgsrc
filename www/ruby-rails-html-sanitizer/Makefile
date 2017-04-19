# $NetBSD: Makefile,v 1.1 2017/04/19 06:48:13 minskim Exp $

DISTNAME=	rails-html-sanitizer-1.0.3
CATEGORIES=	www

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/rails/rails-html-sanitizer
COMMENT=	HTML sanitizer for Rails applications
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-loofah>=2.0:../../www/ruby-loofah

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
