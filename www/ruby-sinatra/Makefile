# $NetBSD: Makefile,v 1.15 2013/12/07 08:43:34 obache Exp $

DISTNAME=	sinatra-1.4.4
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.sinatrarb.com/
COMMENT=	Classy web-development dressed in a DSL
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack>=1.4<2:../../www/ruby-rack
DEPENDS+=	${RUBY_PKGPREFIX}-rack-protection>=1.4<2:../../www/ruby-rack-protection
DEPENDS+=	${RUBY_PKGPREFIX}-tilt>=1.3.4<2:../../textproc/ruby-tilt

RUBY_RDOC_REQD=	3.0

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
