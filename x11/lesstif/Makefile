# $NetBSD: Makefile,v 1.51 2000/07/25 14:42:00 jlam Exp $
# FreeBSD Id: Makefile,v 1.13 1997/09/08 08:34:13 tg Exp
#

BUILD_DEPENDS+=		lynx:../../www/lynx

CONFIGURE_ARGS+=	--disable-build-12
CONFIGURE_ARGS+=	--enable-build-20
CONFIGURE_ARGS+=	--enable-default-20
PLIST_SUBST+=		LOCALBASE=${LOCALBASE}

post-install:
	${TEST} ${PREFIX} = ${LOCALBASE} || \
	${LN} -fs ${PREFIX}/share/aclocal/ac_find_motif.m4 \
		${LOCALBASE}/share/aclocal/ac_find_motif.m4

.include "../../x11/lesstif/Makefile.common"
