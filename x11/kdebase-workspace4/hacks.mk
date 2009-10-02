# $NetBSD: hacks.mk,v 1.1.1.1 2009/10/02 19:37:22 markd Exp $

.if !defined(KDEBASE4_HACKS_MK)
KDEBASE4_HACKS_MK=	# defined

### issue is specific to xproto IPv6 support
.if empty(PKG_OPTIONS:Minet6)
PKG_HACKS+=	X11_X_h
post-wrapper:
	${SED} 's,^#define FamilyInternet6.*,/* undef FamilyInternet6 */,' \
		${BUILDLINK_DIR}/include/X11/X.h >${BUILDLINK_DIR}/include/X11/X.h.new
	${MV} ${BUILDLINK_DIR}/include/X11/X.h.new ${BUILDLINK_DIR}/include/X11/X.h
.endif

.endif
