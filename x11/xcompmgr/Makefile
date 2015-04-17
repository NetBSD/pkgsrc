# $NetBSD: Makefile,v 1.30 2015/04/17 07:00:35 wiz Exp $

DISTNAME=	xcompmgr-1.1.7
CATEGORIES=	x11
MASTER_SITES =	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.freedesktop.org/
COMMENT=	Sample compositing manager for X.org >= 6.8.0

USE_TOOLS+=	pkg-config
GNU_CONFIGURE=	yes
USE_FEATURES=	getopt_long

### XXX You may play around with these if you like; they're simply
###	the #defines from xcompmgr.c placed here for your convenience.
#
XCOMPMGR_DEFS+=		-DCAN_DO_USABLE=1	# default: 0 (damage notification)
#XCOMPMGR_DEFS+=	-DMONITOR_REPAINT=0	# default: 0 (?)
#XCOMPMGR_DEFS+=	-DDEBUG_REPAINT=0	# default: 0 (debugging)
#XCOMPMGR_DEFS+=	-DDEBUG_EVENTS=0	# default: 0 (debugging)
#XCOMPMGR_DEFS+=	-DSHADOWS=1		# default: 1 (shadow support)
#XCOMPMGR_DEFS+=	-DSHARP_SHADOW=0	# default  0 (?)

CPPFLAGS+=	${XCOMPMGR_DEFS}

.include "../../x11/compositeproto/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
