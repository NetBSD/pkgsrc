# $NetBSD: buildlink3.mk,v 1.3 2007/12/16 23:08:05 tron Exp $

.include "../../mk/bsd.fast.prefs.mk"

.if ${X11_TYPE} != "modular" && !exists(${X11BASE}/lib/pkgconfig/xinerama.pc)
.include "../../mk/x11.buildlink3.mk"
.else

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBXINERAMA_BUILDLINK3_MK:=	${LIBXINERAMA_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libXinerama
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NlibXinerama}
BUILDLINK_PACKAGES+=	libXinerama
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libXinerama

.if ${LIBXINERAMA_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libXinerama+=	libXinerama>=1.0.1
BUILDLINK_PKGSRCDIR.libXinerama?=	../../x11/libXinerama
.endif	# LIBXINERAMA_BUILDLINK3_MK

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/xineramaproto/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}

.endif
