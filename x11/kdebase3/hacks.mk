# $NetBSD: hacks.mk,v 1.2 2012/04/19 21:10:24 joerg Exp $

.if !defined(KDEBASE3_HACKS_MK)
KDEBASE3_HACKS_MK=	# defined

### issue is specific to xproto IPv6 support
.if empty(PKG_OPTIONS:Minet6)
PKG_HACKS+=	X11_X_h
post-wrapper:
	${SED} 's,^#define FamilyInternet6.*,/* undef FamilyInternet6 */,' \
		${BUILDLINK_DIR}/include/X11/X.h >${BUILDLINK_DIR}/include/X11/X.h.new
	${MV} ${BUILDLINK_DIR}/include/X11/X.h.new ${BUILDLINK_DIR}/include/X11/X.h
.endif

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
# OpenEXR uses exceptions in the header files
BUILDLINK_TRANSFORM+=	rm:-fno-exceptions
.endif

.endif
