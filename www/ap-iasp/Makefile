# $NetBSD: Makefile,v 1.6 2005/05/16 01:15:34 jlam Exp $

.include "../iasp/Makefile.common"

PKGNAME=	ap-iasp-${IASP_VERSION}
COMMENT=	Apache connector for accessing a iASP proxy server

DEPENDS+=	{iasp-${IASP_VERSION},iasp-${IASP_VERSION}nb*}:../../www/iasp

IASP_SRCDIR=	${IASP_DIR}/bin/apache/source/1.3

WRKSRC=		${WRKDIR}/${IASP_SRCDIR}
APACHE_MODULE=	# defined
MESSAGE_SUBST+=	IASP_DESTDIR=${IASP_DESTDIR}

PKGSRC_USE_TOOLS+=	gtar

post-extract:
	cd ${WRKDIR}; ${GTAR} -xf ${IASP_TARFILE} ${IASP_SRCDIR}

do-build:
	cd ${WRKSRC} && ${APXS} -c -o mod_iasp.so *.c

do-install:
	cd ${WRKSRC} && ${APXS} -i mod_iasp.so

.include "../../www/apache/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
