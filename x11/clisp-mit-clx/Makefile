# $NetBSD: Makefile,v 1.1 2011/04/20 18:40:44 hans Exp $
#

CLISP_MODULE=	clx/mit-clx

PKGNAME=	clisp-mit-clx-$(CLISP_VERSION)
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=clisp/}

MAINTAINER=	hans@netbsd.org
HOMEPAGE=	http://clisp.cons.org/
COMMENT=	CLISP MIT CLX module

MAKE_JOBS_SAFE=	no
NO_CONFIGURE=	yes
MAKE_ENV+=	DESTDIR=${DESTDIR:Q}

do-install:
	mkdir -p ${DESTDIR}${LOCALBASE}/bin ${DESTDIR}${LOCALBASE}/lib/clisp/clx/mit-clx
	(cd ${WRKSRC}/modules/clx/mit-clx && ${MAKE} ${MAKE_ENV} install)

.include "../../lang/clisp/module.mk"

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXau/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
