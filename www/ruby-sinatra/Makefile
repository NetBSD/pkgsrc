# $NetBSD: Makefile,v 1.20 2017/03/20 16:12:05 taca Exp $

DISTNAME=	sinatra-1.4.8
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.sinatrarb.com/
COMMENT=	Classy web-development dressed in a DSL
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack>=1.5<2:../../www/ruby-rack
DEPENDS+=	${RUBY_PKGPREFIX}-rack-protection>=1.4<2:../../www/ruby-rack-protection
DEPENDS+=	${RUBY_PKGPREFIX}-tilt>=1.3.4<3:../../textproc/ruby-tilt

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
