# $NetBSD: Makefile,v 1.6 2004/02/14 17:21:53 jlam Exp $
#

DISTNAME=	raptor-1.0.0
PKGREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	http://www.redland.opensource.ac.uk/dist/source/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.redland.opensource.ac.uk/raptor/
COMMENT=	RDF Parser Toolkit written in C

USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

PKGCONFIG_OVERRIDE+=	${WRKSRC}/raptor.pc.in

.include "../../devel/glib2/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../www/curl/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
