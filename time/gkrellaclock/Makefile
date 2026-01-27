# $NetBSD: Makefile,v 1.4 2026/01/27 08:40:43 wiz Exp $

DISTNAME=	gkrellaclock-0.3.4
PKGREVISION=	3
CATEGORIES=	time sysutils
MASTER_SITES=	${MASTER_SITE_GENTOO:=distfiles/ee/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Nice analog clock for Gkrellm
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${DISTNAME:S/aclock/Aclock/}

USE_TOOLS+=	pkg-config
USE_LIBTOOL=	yes

MAKE_FILE=	${FILESDIR}/Makefile
MAKE_FLAGS+=	INSTALL_LIB_DIR=${INSTALL_LIB_DIR:Q}
MAKE_FLAGS+=	INSTALL_LIB=${INSTALL_LIB:Q}
MAKE_FLAGS+=	PLUGIN_DIR=${PREFIX:Q}/lib/gkrellm2/plugins

.include "../../sysutils/gkrellm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
