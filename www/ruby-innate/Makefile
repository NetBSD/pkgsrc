# $NetBSD: Makefile,v 1.7 2013/03/13 12:44:11 jperkin Exp $

DISTNAME=	innate-2012.12
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@netbsd.org
HOMEPAGE=	http://github.com/manveru/innate
COMMENT=	Powerful web-framework wrapper for Rack
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack14>=1.4.1<1.5:../../www/ruby-rack14

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
