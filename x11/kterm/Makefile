# $NetBSD: Makefile,v 1.4 1999/08/26 05:15:03 sakamoto Exp $

DISTNAME=	kterm-6.2.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=applications/}

PATCH_SITES=	ftp://ftp.sra.co.jp/pub/x11/kterm/ \
		ftp://ftp.ics.nara-wu.ac.jp/pub/wd/src/kterm/
PATCHFILES=	kterm-6.2.0.NFS-xauth.patch \
		kterm-6.2.0-6.2.0.wd0.2.patch.gz
PATCH_DIST_STRIP= -p1

MAINTAINER=	sakamoto@netbsd.org

USE_IMAKE=	yes
USE_XAW=	yes

BUILD_DEFS+=	USE_WALLPAPER

.include "../../mk/bsd.prefs.mk"

XAW_TYPE?=	standard

.if defined(USE_WALLPAPER) && ${USE_WALLPAPER} == YES
DEPENDS+=	xpm-3.4k:../../graphics/xpm
PATCH_SITES+=	http://delegate.uec.ac.jp:8081/club/mma/%7Etakkun/fun/handling/
PATCHFILES+=	KTerm-BGP-1.0.patch.gz
.endif

post-patch:
.if ${XAW_TYPE} != "standard"
	@${ECHO_MSG}  "===>  Applying Xaw scrollbar patch"
	@${PATCH} ${PATCH_ARGS} < ${FILESDIR}/patch-xaw3d
.endif

.include "../../mk/bsd.pkg.mk"
