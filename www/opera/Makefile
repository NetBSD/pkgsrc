# $NetBSD: Makefile,v 1.11 2001/02/20 19:23:24 tron Exp $

DISTNAME=	opera-5.0-b6-20010212.017-static.i386
PKGNAME=	opera-5.0b6
CATEGORIES=	www
MASTER_SITES=	http://opera.online.no/linux/tgz/ \
		ftp://ftp.fh-koblenz.de/pub/InternetClients/Opera/english/4.0b4/linux/intel-x86/static/ \
		http://www.wireweb.net/users/quasar/tgz/ \
		ftp://gd.tuwien.ac.at/infosys/browsers/opera/linux/tgz/tgz/ \
		ftp://sunsite.cnlab-switch.ch/mirror/opera/linux/tgz/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.opera.com/
COMMENT=	Small, fast and customizable WWW client

DEPENDS+=	suse_compat>=6.4:../../emulators/suse_compat
DEPENDS+=	suse_libjpeg>=6.4:../../emulators/suse_libjpeg
DEPENDS+=	suse_libpng>=6.4:../../emulators/suse_libpng
DEPENDS+=	suse_x11>=6.4:../../emulators/suse_x11

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
	${INSTALL_DATA} LICENSE ${PREFIX}/share/doc/opera && \
	${INSTALL_DATA} opera.adr opera.desktop opera.wmconfig opera.xpm \
	  opera_*.png ${PREFIX}/share/opera && \
	${INSTALL_DATA} buttons/default/* ${PREFIX}/share/opera/buttons/default && \
	${INSTALL_DATA} buttons/defsmall/* ${PREFIX}/share/opera/buttons/defsmall && \
	${INSTALL_DATA} images/* ${PREFIX}/share/opera/images && \
	${INSTALL_DATA} styles/* ${PREFIX}/share/opera/styles
	${LN} -fs ${PREFIX}/share/opera ${EMULDIR}/usr/share

.include "../../mk/bsd.pkg.mk"
