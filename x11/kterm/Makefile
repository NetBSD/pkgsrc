# $NetBSD: Makefile,v 1.63 2017/05/09 14:18:46 jperkin Exp $

DISTNAME=	kterm-6.2.0
PKGREVISION=	24
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=applications/}

# the following patch includes NFS xauth patch, and kamo's wd0.2 patch.
PATCH_SITES=	${MASTER_SITE_LOCAL}
PATCHFILES=	kterm-6.2.0-termios-wd0.2.patch2 \
		kterm-6.2.0-scroll-wd0.2.patch \
		kterm-6.2.0.NFS-xauth.patch \
		kterm-6.2.0.ext06.patch.gz
PATCH_DIST_STRIP= -p1

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	# none
COMMENT=	Multi-lingual terminal emulator for X

USE_IMAKE=	YES
USE_TOOLS+=	m4

SPECIAL_PERMS=	${PREFIX:Q}/bin/kterm ${SETUID_ROOT_PERMS}

.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/xaw.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
