# $NetBSD: Makefile,v 1.23 2026/08/03 13:12:34 wiz Exp $

DISTNAME=	xmx-2.1alpha.pl7
PKGNAME=	xmx-2.1a7
PKGREVISION=	9
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.cs.brown.edu/pub/xmx/

PATCH_SITES=		http://www.NetBSD.org/~dholland/patchkits/xmx/
PATCHFILES=		xmx-jumbo-patch-20140912.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cs.brown.edu/software/xmx/
COMMENT=	X11 Protocol Multiplexor

MAKE_JOBS_SAFE=	no
USE_IMAKE=	yes
MAKE_FLAGS+=	EXTRA_LDOPTIONS=${LDFLAGS:Q}
MAKE_FLAGS+=	SHLIBGLOBALSFLAGS=${LDFLAGS:Q}

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
