# $NetBSD: Makefile,v 1.2 2004/10/03 00:18:21 tv Exp $
#

DISTNAME=	scew-0.3.1
PKGREVISION=	1
CATEGORIES=	textproc devel
MASTER_SITES=	http://www.ccd.uab.es/~aleix/scew/

MAINTAINER=	thorbjorn@jemander.net
HOMEPAGE=	http://www.nongnu.org/scew/
COMMENT=	Light-weight DOM-like object model API for Expat

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES

PKGCONFIG_OVERRIDE=	etc/pkg-config/scew.pc.in

.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
