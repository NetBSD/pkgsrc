# $NetBSD: Makefile,v 1.12 2023/01/29 21:15:19 ryoon Exp $
#

DISTNAME=	Tktable2.10
PKGNAME=	${DISTNAME:S/Tktable/tktable-/}
PKGREVISION=	9
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tktable/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tktable.sourceforge.net/
COMMENT=	Full-featured 2D table widget for Tk
LICENSE=	2-clause-bsd

# Racy generation of tkTable.tcl.h
MAKE_JOBS_SAFE=	no

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--x-includes=${BUILDLINK_PREFIX.libX11}/include \
			--x-libraries=${BUILDLINK_PREFIX.libX11}/lib
CONFIGURE_ENV+=		PKG_LIBS=${X11_LDFLAGS:Q}

.include "options.mk"

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
