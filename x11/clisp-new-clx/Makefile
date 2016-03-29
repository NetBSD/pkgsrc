# $NetBSD: Makefile,v 1.5 2016/03/29 21:58:40 joerg Exp $
#

CLISP_MODULE=	clx/new-clx

PKGNAME=	clisp-new-clx-${CLISP_VERSION}
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=clisp/}

MAINTAINER=	hans@NetBSD.org
HOMEPAGE=	http://clisp.cons.org/
COMMENT=	CLISP New CLX module

MAKE_JOBS_SAFE=	no

.include "../../lang/clisp/module.mk"

post-configure:
	(cd ${WRKSRC}/modules && ${CC} ${CPPFLAGS} ${CFLAGS} -o ccmp2c ../utils/ccmp2c.c)

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXau/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
