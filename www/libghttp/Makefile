# $NetBSD: Makefile,v 1.9.2.1 2002/06/30 06:24:33 jlam Exp $

DISTNAME=		libghttp-1.0.9
CATEGORIES=		www gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/libghttp/}

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		GNOME http client library

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
