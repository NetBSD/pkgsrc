# $NetBSD: Makefile,v 1.23 2012/10/29 05:06:57 asau Exp $

DISTNAME=	xautolock-pl15
PKGNAME=	xautolock-1.15
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=applications/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Activate xlock after a user defined time of inactivity

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_IMAKE=	YES

.include "../../x11/libXScrnSaver/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
