# $NetBSD: Makefile,v 1.2 2004/02/14 18:26:30 jmmv Exp $
#

DISTNAME=		render-0.8
CATEGORIES=		x11
MASTER_SITES=		http://pdx.freedesktop.org/software/fontconfig/releases/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://pdx.freedesktop.org/software/fontconfig/releases/
COMMENT=		Headers for X11 render extension

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
PKGCONFIG_OVERRIDE+=	render.pc.in
GNU_CONFIGURE=		yes

CONFLICTS=		Xrender<0.8

.include "../../mk/bsd.pkg.mk"
