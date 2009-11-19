# $NetBSD: Makefile,v 1.1.1.1 2009/11/19 14:06:44 fhajny Exp $

DISTNAME=	innate-2009.10
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://github.com/manveru/innate
COMMENT=	Powerful web-framework wrapper for Rack
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${RUBY_PKGPREFIX}-rack>=1.0.0:../../www/ruby-rack

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
