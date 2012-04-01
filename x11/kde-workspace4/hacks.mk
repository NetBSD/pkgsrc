# $NetBSD: hacks.mk,v 1.2 2012/04/01 20:53:16 markd Exp $

.if !defined(KDEBASE4_HACKS_MK)
KDEBASE4_HACKS_MK=	# defined

# fix up buildlinks failure to build link tree correctly
post-wrapper: post-wrapper-extra
	ln -s ${BUILDLINK_PREFIX.qt4-libs}/qt4/mkspecs/default ${BUILDLINK_DIR}/qt4/mkspecs/default

### issue is specific to xproto IPv6 support
.if empty(PKG_OPTIONS:Minet6)
PKG_HACKS+=	X11_X_h
post-wrapper-extra:
	${SED} 's,^#define FamilyInternet6.*,/* undef FamilyInternet6 */,' \
		${BUILDLINK_DIR}/include/X11/X.h >${BUILDLINK_DIR}/include/X11/X.h.new
	${MV} -f ${BUILDLINK_DIR}/include/X11/X.h.new ${BUILDLINK_DIR}/include/X11/X.h
.else
post-wrapper-extra:
.endif

.endif
