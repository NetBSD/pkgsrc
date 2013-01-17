# $NetBSD: Makefile,v 1.9 2013/01/17 12:44:58 taca Exp $

DISTNAME=	sinatra-1.3.3
PKGREVISION=	1
CATEGORIES=	www

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.sinatrarb.com/
COMMENT=	Classy web-development dressed in a DSL
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack>=1.3.6<2:../../www/ruby-rack
DEPENDS+=	${RUBY_PKGPREFIX}-rack-protection>=1.2<2:../../www/ruby-rack-protection
DEPENDS+=	${RUBY_PKGPREFIX}-tilt>=1.3.3<2:../../textproc/ruby-tilt

OVERRIDE_GEMSPEC+= rack-protection~>1
RUBY_RDOC_REQD=	3.0

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
