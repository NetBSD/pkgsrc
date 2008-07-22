# $NetBSD: buildlink3.mk,v 1.2 2008/07/22 03:21:38 dholland Exp $

.include "../../mk/bsd.fast.prefs.mk"

.if ${X11_TYPE} != "modular"
.include "../../mk/x11.buildlink3.mk"
.else

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBXVMC_BUILDLINK3_MK:=	${LIBXVMC_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libXvMC
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NlibXvMC}
BUILDLINK_PACKAGES+=	libXvMC
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libXvMC

.if ${LIBXVMC_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libXvMC+=	libXvMC>=1.0.2
BUILDLINK_PKGSRCDIR.libXvMC?=	../../x11/libXvMC
.endif	# LIBXVMC_BUILDLINK3_MK

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.include "../../x11/videoproto/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}

.endif
