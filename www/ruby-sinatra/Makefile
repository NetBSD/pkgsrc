# $NetBSD: Makefile,v 1.31 2023/01/04 15:27:59 taca Exp $

DISTNAME=	sinatra-3.0.5
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.sinatrarb.com/
COMMENT=	Classy web-development dressed in a DSL
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack2>=2.2:../../www/ruby-rack2
DEPENDS+=	${RUBY_PKGPREFIX}-rack-protection>=3.0.5<3.1:../../www/ruby-rack-protection
DEPENDS+=	${RUBY_PKGPREFIX}-mustermann>=3.0<4:../../www/ruby-mustermann
DEPENDS+=	${RUBY_PKGPREFIX}-tilt>=2.0<3:../../textproc/ruby-tilt

USE_LANGUAGES=	# empty

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
