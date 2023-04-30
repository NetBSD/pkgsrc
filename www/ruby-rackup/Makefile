# $NetBSD: Makefile,v 1.1 2023/04/30 14:35:54 taca Exp $

DISTNAME=	rackup-2.1.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rack/rackup
COMMENT=	General server command for Rack applications
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack>=3:../../www/ruby-rack
DEPENDS+=	${RUBY_PKGPREFIX}-webrick>=1.8<2:../../www/ruby-webrick

USE_LANGUAGES=	# none

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
