# $NetBSD: Makefile,v 1.2 2001/09/27 23:18:46 jlam Exp $

DISTNAME=		Sablot-0.60
PKGNAME=		sablotron-0.60
CATEGORIES=		textproc
MASTER_SITES=		http://www.gingerall.com/perl/rd?url=sablot/

MAINTAINER=		uithuis@dds.nl
HOMEPAGE=		http://www.gingerall.com/charlie-bin/get/webGA/act/sablotron.act
COMMENT=		XSL processor fully implemented in C++

DEPENDS+=		expat-[0-9]*:../../textproc/expat

GNU_CONFIGURE=  	YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/tools/ltconfig

CPPFLAGS=		-I${LOCALBASE}/include -L${LOCALBASE}/lib

.include "../../mk/bsd.pkg.mk"
