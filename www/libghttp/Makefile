# $NetBSD: Makefile,v 1.9 2001/06/30 09:59:50 zuntum Exp $

DISTNAME=		libghttp-1.0.9
CATEGORIES=		www gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/libghttp/}

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		GNOME http client library

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
