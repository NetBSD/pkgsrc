# $NetBSD: Makefile,v 1.10 2004/05/07 01:14:50 xtraeme Exp $
#

DISTNAME=	raptor-1.0.0
PKGREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	http://www.redland.opensource.ac.uk/dist/source/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.redland.opensource.ac.uk/raptor/
COMMENT=	RDF Parser Toolkit written in C

USE_BUILDLINK3=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

PKGCONFIG_OVERRIDE+=	raptor.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
