# $NetBSD: Makefile,v 1.28 2020/03/20 16:30:26 taca Exp $

DISTNAME=	sinatra-2.0.8.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.sinatrarb.com/
COMMENT=	Classy web-development dressed in a DSL
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack>=2.0<3:../../www/ruby-rack
DEPENDS+=	${RUBY_PKGPREFIX}-rack-protection>=2.0.8.1<2.0.9:../../www/ruby-rack-protection
DEPENDS+=	${RUBY_PKGPREFIX}-mustermann>=1.0<2:../../www/ruby-mustermann
DEPENDS+=	${RUBY_PKGPREFIX}-tilt>=2.0<3:../../textproc/ruby-tilt

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
