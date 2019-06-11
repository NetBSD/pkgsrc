# $NetBSD: Makefile,v 1.15 2019/06/11 08:13:05 wiz Exp $

DISTNAME=	sessreg-1.1.2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Manage utmp/wtmp entries for xdm

USE_TOOLS+=	pkg-config
GNU_CONFIGURE=	yes

BUILD_DEFS+=	VARBASE
CONFIGURE_ARGS+=--localstatedir=${VARBASE:Q}

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mgcc)
# required for filenames.sed on gcc5+
CPPFLAGS+=	-P
.endif

.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
