# $NetBSD: Makefile,v 1.11 2001/02/17 17:37:43 wiz Exp $
#

DISTNAME=	t1lib-1.0.1
CATEGORIES=	textproc devel graphics
MASTER_SITES=	${MASTER_SITE_SUNSITE:=libs/graphics/} \
		ftp://ftp.neuroinformatik.ruhr-uni-bochum.de/pub/software/t1lib/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.neuroinformatik.ruhr-uni-bochum.de/ini/PEOPLE/rmz/t1lib/t1lib.html
COMMENT=	Library for generating bitmaps from Adobe Type 1 fonts

GNU_CONFIGURE=	# defined
USE_GMAKE=	# defined
USE_LIBTOOL=	# defined
USE_X11BASE=	# defined

WRKSRC=		${WRKDIR}/T1-1.0.1
ALL_TARGET=	without_doc

post-install:
	${MKDIR} ${PREFIX}/share/t1lib
	cd ${WRKSRC}; \
	  ${PAX} -rw Fonts ${PREFIX}/share/t1lib; \
	  ${CHMOD} go+r ${PREFIX}/share/t1lib/Fonts/enc/IsoLatin2.enc; \
	  ${PAX} -rw -s "/doc/t1lib/" doc ${PREFIX}/share/doc

	${MKDIR} ${PREFIX}/share/examples/t1lib
	cd ${WRKSRC}/examples; \
	  ${PAX} -rw FontDataBase README.t1example1 t1example1.c t1lib.config \
	      ${PREFIX}/share/examples/t1lib
	${SED}	-e 's|@@X11BASE@@|${X11BASE}|g' \
		-e 's|@@LOCALBASE@@|${LOCALBASE}|g' \
		-e 's|@@PREFIX@@|${PREFIX}|g' \
		< ${FILESDIR}/t1lib.config.netbsd \
		> ${PREFIX}/share/examples/t1lib/t1lib.config.netbsd

	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
