# $NetBSD: Makefile,v 1.2 2004/10/03 00:18:39 tv Exp $
#

DISTNAME=	xcompmgr-cvs-20040914
PKGNAME=	${DISTNAME:S/-cvs//}
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.NetBSD.org/pub/NetBSD/misc/xtraeme/
EXTRACT_SUFX=	.tgz

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.freedesktop.org/
COMMENT=	Sample compositing manager for X.org >= 6.8.0

WRKSRC=		${WRKDIR}/${PKGBASE}
GNU_CONFIGURE=	yes
USE_BUILDLINK3=	yes
USE_X11=	yes

pre-configure:
	cd ${WRKSRC};			\
	${ACLOCAL};			\
	${AUTOHEADER};			\
	${AUTOMAKE} -a --foreign -i;	\
	${AUTOCONF}

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../x11/Xrender/buildlink3.mk"
.include "../../mk/automake.mk"
.include "../../mk/bsd.pkg.mk"
