# $NetBSD: Makefile,v 1.3 2017/06/21 15:42:11 taca Exp $

DISTNAME=	rails-deprecated_sanitizer-1.0.3
PKGREVISION=	1
CATEGORIES=	www

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/rails/rails-deprecated_sanitizer
COMMENT=	Deprecated sanitizer API extracted from Action View
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}

RUBY_RAILS_SUPPORTED=	42

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
