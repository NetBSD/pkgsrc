# $NetBSD: Makefile,v 1.4 2013/04/01 05:50:22 sbd Exp $
#

DISTNAME=	libDesktop-0.0.8
PKGNAME=	deforaos-libdesktop-0.0.8
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://www.defora.org/os/download/download/3699/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.defora.org/
COMMENT=	DeforaOS desktop library

LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config
MAKE_JOBS_SAFE=	no

MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	INSTALL=${INSTALL}

# Don't use non-portable ${INSTALL} arguments
SUBST_CLASSES+=		nodashes
SUBST_STAGE.nodashes=	pre-configure
SUBST_FILES.nodashes=	include/Makefile include/Desktop/Makefile
SUBST_FILES.nodashes+=	src/Makefile
SUBST_SED.nodashes=	-e '/INSTALL/s/ -- / /'

.include "../../devel/deforaos-libsystem/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
