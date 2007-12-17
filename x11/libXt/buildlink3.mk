# $NetBSD: buildlink3.mk,v 1.4 2007/12/17 15:02:26 tron Exp $

.include "../../mk/bsd.fast.prefs.mk"

.if ${X11_TYPE} != "modular" && !exists(${X11BASE}/lib/pkgconfig/xt.pc)
.include "../../mk/x11.buildlink3.mk"
.else

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBXT_BUILDLINK3_MK:=	${LIBXT_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libXt
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NlibXt}
BUILDLINK_PACKAGES+=	libXt
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libXt

.if ${LIBXT_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libXt+=	libXt>=1.0.0
BUILDLINK_PKGSRCDIR.libXt?=	../../x11/libXt
.endif	# LIBXT_BUILDLINK3_MK

.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}

.endif
