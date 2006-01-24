# $NetBSD: Makefile,v 1.9 2006/01/24 07:32:42 wiz Exp $

.include "../../www/iasp/Makefile.common"

PKGNAME=	ap-iasp-${IASP_VERSION}
PKGREVISION=	1
COMMENT=	Apache connector for accessing a iASP proxy server

DEPENDS+=	{iasp-${IASP_VERSION},iasp-${IASP_VERSION}nb*}:../../www/iasp

IASP_SRCDIR=	${IASP_DIR}/bin/apache/source/1.3

WRKSRC=		${WRKDIR}/${IASP_SRCDIR}
APACHE_MODULE=	# defined
MESSAGE_SUBST+=	IASP_DESTDIR=${IASP_DESTDIR}

USE_TOOLS+=	gtar

post-extract:
	cd ${WRKDIR}; ${GTAR} -xf ${IASP_TARFILE} ${IASP_SRCDIR}

do-build:
	cd ${WRKSRC} && ${APXS} -c -o mod_iasp.so *.c

do-install:
	cd ${WRKSRC} && ${APXS} -i mod_iasp.so

.include "../../www/apache/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
