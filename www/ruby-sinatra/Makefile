# $NetBSD: Makefile,v 1.2 2011/09/22 04:31:26 obache Exp $

DISTNAME=	sinatra-1.2.6
CATEGORIES=	www

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.sinatrarb.com/
COMMENT=	Classy web-development dressed in a DSL
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack>=1.1:../../www/ruby-rack11
DEPENDS+=	${RUBY_PKGPREFIX}-tilt>=1.2.2:../../textproc/ruby-tilt

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
