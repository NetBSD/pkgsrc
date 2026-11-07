# $NetBSD: Makefile,v 1.1 2026/11/07 15:05:02 taca Exp $

DISTNAME=	json-schema-6.2.1
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/voxpupuli/json-schema
COMMENT=	Ruby JSON Schema Validator
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-addressable>=2.8<3:../../net/ruby-addressable

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
