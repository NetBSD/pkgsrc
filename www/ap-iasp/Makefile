# $NetBSD: Makefile,v 1.2 2003/03/29 12:42:47 jmmv Exp $

.include "../iasp/Makefile.common"

PKGNAME=	ap-iasp-${IASP_VERSION}
WRKSRC=		${WRKDIR}/${IASP_SRCDIR}
COMMENT=	Apache connector for accessing a iASP proxy server

DEPENDS+=	{iasp-${IASP_VERSION},iasp-${IASP_VERSION}nb*}:../../www/iasp

IASP_SRCDIR=	${IASP_DIR}/bin/apache/source/1.3

USE_BUILDLINK2=	# defined
APACHE_MODULE=	# defined
MESSAGE_SUBST+=	IASP_DESTDIR=${IASP_DESTDIR}

post-extract:
	cd ${WRKDIR}; ${GTAR} -xf ${IASP_TARFILE} ${IASP_SRCDIR}

do-build:
	cd ${WRKSRC} && ${APXS} -c -o mod_iasp.so *.c

do-install:
	cd ${WRKSRC} && ${APXS} -i mod_iasp.so

.include "../../www/apache/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
