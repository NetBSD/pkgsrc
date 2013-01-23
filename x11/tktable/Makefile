# $NetBSD: Makefile,v 1.1 2013/01/23 21:58:25 wiz Exp $
#

DISTNAME=	Tktable2.10
PKGNAME=	${DISTNAME:S/Tktable/tktable-/}
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tktable/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tktable.sourceforge.net/
COMMENT=	Full-featured 2D table widget for Tk
LICENSE=	2-clause-bsd

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--x-includes=${BUILDLINK_PREFIX.libX11}/include \
			--x-libraries=${BUILDLINK_PREFIX.libX11}/lib

.include "options.mk"

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
