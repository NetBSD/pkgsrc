# $NetBSD: Makefile,v 1.7 2004/10/03 00:18:23 tv Exp $
#

DISTNAME=	menu2wm-0.2
PKGREVISION=	2
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=menu2wm/}

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://menu2wm.sourceforge.net/
COMMENT=	Convert an XML menu to the format used by common WMs

USE_BUILDLINK3=	YES

.include "../../devel/buildtool/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
