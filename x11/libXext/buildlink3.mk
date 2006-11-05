# $NetBSD: buildlink3.mk,v 1.2 2006/11/05 16:55:28 joerg Exp $

.include "../../mk/bsd.fast.prefs.mk"

.if ${X11_TYPE} != "modular"
.include "../../mk/x11.buildlink3.mk"
.else

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBXEXT_BUILDLINK3_MK:=	${LIBXEXT_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libXext
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NlibXext}
BUILDLINK_PACKAGES+=	libXext
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libXext

.if ${LIBXEXT_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libXext+=	libXext>=0.99.0
BUILDLINK_PKGSRCDIR.libXext?=	../../x11/libXext
.endif	# LIBXEXT_BUILDLINK3_MK

.include "../../x11/libX11/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}

.endif
