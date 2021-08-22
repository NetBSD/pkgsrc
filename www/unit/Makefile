# $NetBSD: Makefile,v 1.5 2021/08/22 05:10:19 gutteridge Exp $

.include "../../www/unit/version.mk"

DISTNAME=	unit-${UNIT_VERSION}

COMMENT=	Dynamic web application server

MAINTAINER=	osa@FreeBSD.org

RCD_SCRIPTS=	unit

BUILDLINK_TRANSFORM.SunOS+=	rm:-Werror
	
.include "../../www/unit/Makefile.common"
.include "../../mk/bsd.pkg.mk"
