# $NetBSD: Makefile,v 1.4 2021/12/12 15:24:24 taca Exp $

MODNAME=	yaml
PECL_VERSION=	2.2.2

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	YAML-1.1 parser and emitter
LICENSE=	mit

PHP_VERSIONS_INCOMPATIBLE=	56

CONFIGURE_ARGS+=	--enable-${MODNAME}

.include "../../textproc/libyaml/buildlink3.mk"

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
