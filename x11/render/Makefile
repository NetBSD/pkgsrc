# $NetBSD: Makefile,v 1.3 2004/02/16 09:16:13 jlam Exp $

DISTNAME=		render-0.8
CATEGORIES=		x11
MASTER_SITES=		http://pdx.freedesktop.org/software/fontconfig/releases/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://pdx.freedesktop.org/software/fontconfig/releases/
COMMENT=		headers for X11 render extension

CONFLICTS=		Xrender<0.8

USE_BUILDLINK3=		yes
USE_LANGUAGES=		# empty
USE_PKGLOCALEDIR=	yes
PKGCONFIG_OVERRIDE+=	render.pc.in
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
