# $NetBSD: Makefile,v 1.2 2022/08/31 16:05:38 taca Exp $

DISTNAME=	request_store-1.5.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/steveklabnik/request_store
COMMENT=	Per-request global storage for Rack
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack>=1.4:../../www/ruby-rack

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
