# $NetBSD: Makefile,v 1.2 2025/02/11 08:10:56 wiz Exp $

DISTNAME=	libhubbub-0.3.8-src
PKGNAME=	${DISTNAME:S/-src$//}
CATEGORIES=	www
MASTER_SITES=	https://download.netsurf-browser.org/libs/releases/
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.netsurf-browser.org/projects/hubbub/
COMMENT=	HTML5 compliant parsing library
LICENSE=	mit

TOOL_DEPENDS+=	gperf-[0-9]*:../../devel/gperf
TOOL_DEPENDS+=	netsurf-buildsystem-[0-9]*:../../devel/netsurf-buildsystem

USE_LANGUAGES=		c
USE_CC_FEATURES=	c99
USE_TOOLS+=		gmake perl

MAKE_ENV+=	PREFIX=${PREFIX:Q}
MAKE_ENV+=	COMPONENT_TYPE=lib-shared
MAKE_ENV+=	PKGCONFIG=${TOOLS_CMD.pkg-config:Q}

BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../textproc/libparserutils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
