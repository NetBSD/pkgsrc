# $NetBSD: Makefile,v 1.5 2025/02/08 03:55:19 taca Exp $

MODNAME=	yaml
PECL_VERSION=	2.2.2
PKGREVISION=	1

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	YAML-1.1 parser and emitter
LICENSE=	mit

PHP_VERSIONS_INCOMPATIBLE=	56

CONFIGURE_ARGS+=	--enable-${MODNAME}

.include "../../textproc/libyaml/buildlink3.mk"

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
