# $NetBSD: Makefile,v 1.3 2001/10/05 07:15:12 jlam Exp $

DISTNAME=		Sablot-0.60
PKGNAME=		sablotron-0.60
CATEGORIES=		textproc
MASTER_SITES=		http://www.gingerall.com/perl/rd?url=sablot/

MAINTAINER=		uithuis@dds.nl
HOMEPAGE=		http://www.gingerall.com/charlie-bin/get/webGA/act/sablotron.act
COMMENT=		XSL processor fully implemented in C++

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=  	YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/tools/ltconfig

.include "../../textproc/expat/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
