# $NetBSD: Makefile,v 1.2 2019/01/14 13:06:11 taca Exp $

MODNAME=	yaml
PECL_VERSION=	2.0.0

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	YAML-1.1 parser and emitter
LICENSE=	mit

PHP_VERSIONS_ACCEPTED=	71

CONFIGURE_ARGS+=	--enable-${MODNAME}

.include "../../textproc/libyaml/buildlink3.mk"

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
