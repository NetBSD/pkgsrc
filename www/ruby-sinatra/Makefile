# $NetBSD: Makefile,v 1.34 2025/11/03 07:35:56 taca Exp $

DISTNAME=	sinatra-4.2.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.sinatrarb.com/
COMMENT=	Classy web-development dressed in a DSL
LICENSE=	mit

#DEPENDS+=	${RUBY_PKGPREFIX}-rack>=3.0.0<4:../../www/ruby-rack
DEPENDS+=	${RUBY_PKGPREFIX}-rack-protection>=4.2.1:../../www/ruby-rack-protection
DEPENDS+=	${RUBY_PKGPREFIX}-rack-session>=2.0.0<3:../../www/ruby-rack-session
DEPENDS+=	${RUBY_PKGPREFIX}-mustermann>=3.0<4:../../www/ruby-mustermann
DEPENDS+=	${RUBY_PKGPREFIX}-tilt>=2.0<3:../../textproc/ruby-tilt

USE_LANGUAGES=	# empty

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
