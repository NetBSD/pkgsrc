# $NetBSD: Makefile,v 1.52 2000/10/23 19:45:05 jlam Exp $
# FreeBSD Id: Makefile,v 1.13 1997/09/08 08:34:13 tg Exp
#

BUILD_DEPENDS+=		lynx:../../www/lynx

CONFIGURE_ARGS+=	--disable-build-12
CONFIGURE_ARGS+=	--enable-build-20
CONFIGURE_ARGS+=	--enable-default-20

DEINSTALL_FILE=		${WRKDIR}/DEINSTALL
INSTALL_FILE=		${WRKDIR}/INSTALL

post-build:
	${SED}	-e "s,@LOCALBASE@,${LOCALBASE},g" \
		-e "s,@X11BASE@,${X11BASE},g" \
		< ${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
	${SED}	-e "s,@LOCALBASE@,${LOCALBASE},g" \
		-e "s,@X11BASE@,${X11BASE},g" \
		< ${PKGDIR}/INSTALL > ${INSTALL_FILE}

post-install:
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../x11/lesstif/Makefile.common"
