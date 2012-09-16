# $NetBSD: Makefile,v 1.6 2012/09/16 13:39:33 taca Exp $

DISTNAME=	sinatra-1.3.3
CATEGORIES=	www

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.sinatrarb.com/
COMMENT=	Classy web-development dressed in a DSL
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack>=1.3.6<2:../../www/ruby-rack
DEPENDS+=	${RUBY_PKGPREFIX}-rack-protection>=1.2<2:../../www/ruby-rack-protection
DEPENDS+=	${RUBY_PKGPREFIX}-tilt>=1.3.3<2:../../textproc/ruby-tilt

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
