# $NetBSD: Makefile,v 1.6 2026/01/02 06:13:57 taca Exp $

MODNAME=	yaml
PECL_VERSION=	2.3.0

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	YAML-1.1 parser and emitter
LICENSE=	mit

PHP_VERSIONS_INCOMPATIBLE=	56

CONFIGURE_ARGS+=	--enable-${MODNAME}

.include "../../textproc/libyaml/buildlink3.mk"

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
