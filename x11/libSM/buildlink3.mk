# $NetBSD: buildlink3.mk,v 1.5 2014/03/10 11:05:52 jperkin Exp $

.include "../../mk/bsd.fast.prefs.mk"

.if ${X11_TYPE} != "modular" && \
    !exists(${X11BASE}/lib/pkgconfig/sm.pc) && \
    !exists(${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/sm.pc)
.include "../../mk/x11.buildlink3.mk"
.else

BUILDLINK_TREE+=	libSM

.if !defined(LIBSM_BUILDLINK3_MK)
LIBSM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libSM+=	libSM>=0.99.2
BUILDLINK_PKGSRCDIR.libSM?=	../../x11/libSM

.include "../../x11/libICE/buildlink3.mk"
.endif # LIBSM_BUILDLINK3_MK

BUILDLINK_TREE+=	-libSM

.endif
