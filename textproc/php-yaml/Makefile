# $NetBSD: Makefile,v 1.1 2016/12/01 12:23:47 roy Exp $

MODNAME=	yaml
PECL_VERSION=	2.0.0

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	YAML-1.1 parser and emitter
LICENSE=	mit

PHP_VERSIONS_ACCEPTED=	70 71

CONFIGURE_ARGS+=	--enable-${MODNAME}

.include "../../textproc/libyaml/buildlink3.mk"

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
