# $NetBSD: Makefile,v 1.4 2000/12/22 17:26:22 jlam Exp $

PKGNAME=		lesstif12-${LESSTIF_VERSION}

CONFLICTS+=		lesstif-0.[0-8]*
CONFLICTS+=		lesstif-0.90*
CONFLICTS+=		lesstif-0.91 lesstif-0.91.[0-3]
CONFLICTS+=		openmotif-*

CONFIGURE_ARGS+=	--enable-build-12
CONFIGURE_ARGS+=	--disable-build-20
CONFIGURE_ARGS+=	--enable-default-12

MESSAGE_FILE=		${WRKDIR}/MESSAGE

pre-install:
	${SED} -e "s,@PREFIX@,${PREFIX},g" \
		< ${PKGDIR}/MESSAGE > ${MESSAGE_FILE}

# We don't install any documentation, but the installation process creates
# this directory anyway, so remove it if it's empty.
#
post-install:
	${RMDIR} -p ${PREFIX}/share/doc/html/lesstif 2> /dev/null || ${TRUE}

.include "../../x11/lesstif/Makefile.common"
