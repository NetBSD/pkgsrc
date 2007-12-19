# $NetBSD: Makefile,v 1.21 2007/12/19 05:43:30 bjs Exp $
#

DISTNAME=	xcompmgr-1.1.3
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://xapps.freedesktop.org/release/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.freedesktop.org/
COMMENT=	Sample compositing manager for X.org >= 6.8.0

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pkg-config
GNU_CONFIGURE=	yes
USE_FEATURES=	getopt_long

### XXX You may play around with these if you like; they're simply
###	the #defines from xcompmgr.c placed here for your convenience.
#
XCOMPMGR_DEFS+=	-DREPAINT_MONITOR=0	# default: 0 (?)
XCOMPMGR_DEFS+= -DCAN_DO_USABLE=1	# default: 0 (damage notification)
XCOMPMGR_DEFS+=	-DDEBUG_REPAINT=0	# default: 0 (debugging)
XCOMPMGR_DEFS+=	-DDEBUG_REPAINT=0	# default: 0 (debugging)
XCOMPMGR_DEFS+=	-DSHADOWS=1		# default: 1 (shadow support)
XCOMPMGR_DEFS+=	-DSHARP_SHADOW=0	# default  0 (?)

CPPFLAGS+=	${XCOMPMGR_DEFS}

.include "../../mk/bsd.prefs.mk"

.if defined(X11_TYPE) && !empty(X11_TYPE:MXFree86) || \
    defined(X11_TYPE) && !empty(X11_TYPE:Mnative) || !defined(X11_TYPE)
PKG_FAIL_REASON+=	"This package is exclusively for X.org."
.endif

.include "../../x11/compositeproto/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
