# $NetBSD: Makefile,v 1.3 2019/04/27 22:40:59 roy Exp $

MODNAME=	yaml
PECL_VERSION=	2.0.4

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	YAML-1.1 parser and emitter
LICENSE=	mit

PHP_VERSIONS_INCOMPATIBLE=	56

CONFIGURE_ARGS+=	--enable-${MODNAME}

.include "../../textproc/libyaml/buildlink3.mk"

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
