# $NetBSD: Makefile,v 1.12 2003/07/17 22:55:39 grant Exp $

DISTNAME=		libghttp-1.0.9
CATEGORIES=		www gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/libghttp/1.0/}

MAINTAINER=		tron@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		GNOME http client library

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
