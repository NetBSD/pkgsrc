# $NetBSD: Makefile,v 1.3 2000/11/29 13:24:00 hubertf Exp $

DISTNAME=	opera-4.0-b3-static.i386
PKGNAME=	opera-4.0b3
CATEGORIES=	www
MASTER_SITES=	http://opera.online.no/linux/tgz/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.opera.com/

DEPENDS+=	suse_libjpeg>=6.4:../../emulators/suse_libjpeg
DEPENDS+=	suse_x11>=6.3:../../emulators/suse_x11

ONLY_FOR_PLATFORM=	NetBSD-*-i386

LICENSE=	opera-license

CHECK_SHLIBS=	NO
EMULSUBDIR=	emul/linux
EMULDIR=	${PREFIX}/${EMULSUBDIR}
NO_BUILD=	YES
PLIST_SUBST=	EMULSUBDIR=${EMULSUBDIR}

do-install:
	${INSTALL_DATA_DIR} \
		${PREFIX}/share/doc/opera \
		${PREFIX}/share/opera/buttons \
		${PREFIX}/share/opera/buttons/default \
		${PREFIX}/share/opera/buttons/defsmall \
		${PREFIX}/share/opera/images \
		${PREFIX}/share/opera/styles
	cd ${WRKSRC} && \
	${INSTALL_SCRIPT} opera ${PREFIX}/bin && \
	${INSTALL_DATA} LICENSE README ${PREFIX}/share/doc/opera && \
	${INSTALL_DATA} opera.adr ${PREFIX}/share/opera && \
	${INSTALL_DATA} buttons/default/* ${PREFIX}/share/opera/buttons/default && \
	${INSTALL_DATA} buttons/defsmall/* ${PREFIX}/share/opera/buttons/defsmall && \
	${INSTALL_DATA} images/* ${PREFIX}/share/opera/images && \
	${INSTALL_DATA} styles/* ${PREFIX}/share/opera/styles
	${LN} -fs ${PREFIX}/share/opera ${EMULDIR}/usr/share

.include "../../mk/bsd.pkg.mk"
