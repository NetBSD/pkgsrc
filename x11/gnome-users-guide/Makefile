# $NetBSD: Makefile,v 1.10 2003/05/02 11:57:02 wiz Exp $

DISTNAME=	users-guide-1.2
PKGNAME=	gnome-users-guide-1.2
PKGREVISION=	2
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/users-guide/1.2/}

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.gnome.org/users-guide/project.shtml
COMMENT=	User documentation for GNOME

DEPENDS+=	gnome-libs>=1.4.1.4nb4:../gnome-libs

GNU_CONFIGURE=	YES
USE_X11BASE=	YES

.include "../../mk/bsd.pkg.mk"
