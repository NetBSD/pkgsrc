# $NetBSD: Makefile,v 1.6 2004/07/04 22:22:41 jmmv Exp $
#

DISTNAME=	menu2wm-0.2
PKGREVISION=	1
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
