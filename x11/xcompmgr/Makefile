# $NetBSD: Makefile,v 1.7 2004/11/29 11:27:02 xtraeme Exp $
#

DISTNAME=	xcompmgr-1.1.1	
CATEGORIES=	x11
MASTER_SITES=	http://freedesktop.org/xapps/release/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.freedesktop.org/
COMMENT=	Sample compositing manager for X.org >= 6.8.0

GNU_CONFIGURE=	yes
USE_BUILDLINK3=	yes
USE_X11=	yes

.include "../../mk/bsd.prefs.mk"

.if defined(X11_TYPE) && !empty(X11_TYPE:MXFree86) || \
    defined(X11_TYPE) && !empty(X11_TYPE:Mnative) || !defined(X11_TYPE)
PKG_SKIP_REASON+=	"This package is exclusively for X.org."
.endif

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../x11/Xcomposite/buildlink3.mk"
.include "../../x11/Xrender/buildlink3.mk"
.include "../../x11/compositeext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
