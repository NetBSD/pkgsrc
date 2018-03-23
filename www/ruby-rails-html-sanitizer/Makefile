# $NetBSD: Makefile,v 1.2 2018/03/23 14:06:32 taca Exp $

DISTNAME=	rails-html-sanitizer-1.0.4
CATEGORIES=	www

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/rails/rails-html-sanitizer
COMMENT=	HTML sanitizer for Rails applications
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-loofah>=2.2.0:../../www/ruby-loofah

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
