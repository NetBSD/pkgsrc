# $NetBSD: Makefile,v 1.53 2000/12/22 17:26:18 jlam Exp $
# FreeBSD Id: Makefile,v 1.13 1997/09/08 08:34:13 tg Exp
#

CONFIGURE_ARGS+=	--disable-build-12
CONFIGURE_ARGS+=	--enable-build-20
CONFIGURE_ARGS+=	--enable-default-20

DEINSTALL_FILE=		${WRKDIR}/DEINSTALL
INSTALL_FILE=		${WRKDIR}/INSTALL

pre-install:
	${SED}	-e "s,@LOCALBASE@,${LOCALBASE},g" \
		-e "s,@CP@,${CP},g" \
		-e "s,@GREP@,${GREP},g" \
		-e "s,@RM@,${RM},g" \
		-e "s,@RMDIR@,${RMDIR},g" \
		-e "s,@TRUE@,${TRUE},g" \
		< ${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
	${SED}	-e "s,@LOCALBASE@,${LOCALBASE},g" \
		-e "s,@CP@,${CP},g" \
		-e "s,@GREP@,${GREP},g" \
		-e "s,@LN@,${LN},g" \
		< ${PKGDIR}/INSTALL > ${INSTALL_FILE}

post-install:
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../x11/lesstif/Makefile.common"
