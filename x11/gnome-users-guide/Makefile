# $NetBSD: Makefile,v 1.7 2001/02/17 17:06:25 wiz Exp $

DISTNAME=	users-guide-1.2
PKGNAME=	gnome-users-guide-1.2
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=stable/sources/users-guide/}

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.gnome.org/users-guide/project.shtml
COMMENT=	User documentation for GNOME

DEPENDS+=	gnome-libs>=1.2.1:../gnome-libs

GNU_CONFIGURE=	YES
USE_X11BASE=	YES

.include "../../mk/bsd.pkg.mk"
