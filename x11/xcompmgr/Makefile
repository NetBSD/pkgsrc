# $NetBSD: Makefile,v 1.17 2006/12/15 20:33:05 joerg Exp $
#

DISTNAME=	xcompmgr-1.1.1
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://freedesktop.org/xapps/release/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.freedesktop.org/
COMMENT=	Sample compositing manager for X.org >= 6.8.0

USE_TOOLS+=	pkg-config
GNU_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"

.if defined(X11_TYPE) && !empty(X11_TYPE:MXFree86) || \
    defined(X11_TYPE) && !empty(X11_TYPE:Mnative) || !defined(X11_TYPE)
PKG_SKIP_REASON+=	"This package is exclusively for X.org."
.endif

.include "../../x11/compositeproto/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
