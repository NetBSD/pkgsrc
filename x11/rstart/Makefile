# $NetBSD: Makefile,v 1.1 2015/07/02 12:38:32 rodent Exp $
#

DISTNAME=	rstart-1.0.5
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Implements "A Flexible Remote Execution Protocol Based on rsh"
#LICENSE=	# TODO: (see mk/license.mk)

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

.include "../../devel/xorg-util-macros/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
