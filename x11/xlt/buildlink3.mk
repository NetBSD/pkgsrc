# $NetBSD: buildlink3.mk,v 1.1 2008/07/15 19:45:40 christos Exp $

.include "../../mk/bsd.fast.prefs.mk"

.if ${X11_TYPE} != "modular"
.include "../../mk/x11.buildlink3.mk"
.else

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBXLT_BUILDLINK3_MK:=	${LIBXLT_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libXlt
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NlibXv}
BUILDLINK_PACKAGES+=	libXv
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libXv

.if ${LIBXLT_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libXlt+=	libXlt>=1.0.1
BUILDLINK_PKGSRCDIR.libXv?=	../../x11/libXlt
.endif	# LIBXLT_BUILDLINK3_MK

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}

.endif
