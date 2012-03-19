# $NetBSD: hacks.mk,v 1.1 2012/03/19 19:44:03 markd Exp $

.if !defined(KDEBASE4_HACKS_MK)
KDEBASE4_HACKS_MK=	# defined

### issue is specific to xproto IPv6 support
.if empty(PKG_OPTIONS:Minet6)
PKG_HACKS+=	X11_X_h
post-wrapper:
	${SED} 's,^#define FamilyInternet6.*,/* undef FamilyInternet6 */,' \
		${BUILDLINK_DIR}/include/X11/X.h >${BUILDLINK_DIR}/include/X11/X.h.new
	${MV} -f ${BUILDLINK_DIR}/include/X11/X.h.new ${BUILDLINK_DIR}/include/X11/X.h
.endif

.endif

# fix up buildlinks failure to build link tree correctly
post-wrapper:
	ln -s netbsd-g++ ${BUILDLINK_DIR}/qt4/mkspecs/default
