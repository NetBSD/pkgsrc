# $NetBSD: Makefile,v 1.1 2020/05/25 14:40:23 taca Exp $

DISTNAME=	request_store-1.5.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/steveklabnik/request_store
COMMENT=	Per-request global storage for Rack
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack>=1.4:../../www/ruby-rack

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
