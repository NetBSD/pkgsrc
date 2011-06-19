# $NetBSD: Makefile,v 1.12 2011/06/19 09:30:49 alnsn Exp $

DISTNAME=	xmx-2.1alpha.pl7
PKGNAME=	xmx-2.1a7
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.cs.brown.edu/pub/xmx/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cs.brown.edu/software/xmx/
COMMENT=	X11 Protocol Multiplexor

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=	no
USE_IMAKE=	yes

.include "../../mk/bsd.prefs.mk"

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
