# $NetBSD: Makefile,v 1.3 2024/12/11 14:38:51 taca Exp $

DISTNAME=	rackup-2.2.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rack/rackup
COMMENT=	General server command for Rack applications
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack>=3:../../www/ruby-rack

USE_LANGUAGES=	# none

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
