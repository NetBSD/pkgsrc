# $NetBSD: Makefile,v 1.5 2004/03/01 17:58:19 reed Exp $

DISTNAME=		render-0.8
CATEGORIES=		x11
MASTER_SITES=		http://pdx.freedesktop.org/software/fontconfig/releases/

MAINTAINER=		jlam@NetBSD.org
HOMEPAGE=		http://pdx.freedesktop.org/software/fontconfig/releases/
COMMENT=		Headers for X11 render extension

CONFLICTS=		Xrender<0.8

USE_BUILDLINK3=		yes
USE_LANGUAGES=		# empty
USE_PKGLOCALEDIR=	yes
PKGCONFIG_OVERRIDE+=	render.pc.in
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
