# $NetBSD: Makefile,v 1.1 2025/11/03 07:06:23 taca Exp $

DISTNAME=	sinatra-3.2.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/sinatra/&3/}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.sinatrarb.com/
COMMENT=	Classy web-development dressed in a DSL
LICENSE=	mit

#DEPENDS+=	${RUBY_PKGPREFIX}-rack2>=2.2:../../www/ruby-rack2
DEPENDS+=	${RUBY_PKGPREFIX}-rack-protection3>=3.2.0<3.3:../../www/ruby-rack-protection3
DEPENDS+=	${RUBY_PKGPREFIX}-mustermann>=3.0<4:../../www/ruby-mustermann
DEPENDS+=	${RUBY_PKGPREFIX}-tilt>=2.0<3:../../textproc/ruby-tilt

USE_LANGUAGES=	# empty

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
