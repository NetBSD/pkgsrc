# $NetBSD: Makefile,v 1.14 2006/02/12 15:29:19 xtraeme Exp $
#

DISTNAME=	xcompmgr-1.1.1
PKGREVISION=	1
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

.include "../../x11/Xcomposite/buildlink3.mk"
.include "../../x11/Xrender/buildlink3.mk"
.include "../../x11/compositeext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
