# $NetBSD: Makefile,v 1.1.1.1 2001/06/25 17:27:34 wiz Exp $

DISTNAME=		Sablot-0.60
PKGNAME=		sablotron-0.60
CATEGORIES=		textproc
MASTER_SITES=		http://www.gingerall.com/perl/rd?url=sablot/

MAINTAINER=		uithuis@dds.nl
HOMEPAGE=		http://www.gingerall.com/charlie-bin/get/webGA/act/sablotron.act
COMMENT=		XSL processor fully implemented in C++

DEPENDS+=		expat-*:../../textproc/expat

GNU_CONFIGURE=  	YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/tools/ltconfig

CPPFLAGS=		-I${LOCALBASE}/include -L${LOCALBASE}/lib

.include "../../mk/bsd.pkg.mk"
