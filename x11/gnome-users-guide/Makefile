# $NetBSD: Makefile,v 1.9 2002/10/19 10:55:02 rh Exp $

DISTNAME=	users-guide-1.2
PKGNAME=	gnome-users-guide-1.2
PKGREVISION=	1
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/users-guide/1.2/}

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.gnome.org/users-guide/project.shtml
COMMENT=	User documentation for GNOME

DEPENDS+=	gnome-libs>=1.4.1.2nb1:../gnome-libs

GNU_CONFIGURE=	YES
USE_X11BASE=	YES

.include "../../mk/bsd.pkg.mk"
