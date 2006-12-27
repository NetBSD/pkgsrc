# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/12/27 12:24:15 joerg Exp $

.include "../../mk/bsd.fast.prefs.mk"

.if ${X11_TYPE} != "modular"
.include "../../mk/x11.buildlink3.mk"
.else

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBXXF86DGA_BUILDLINK3_MK:=	${LIBXXF86DGA_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libXxf86dga
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NlibXxf86dga}
BUILDLINK_PACKAGES+=	libXxf86dga
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libXxf86dga

.if ${LIBXXF86DGA_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libXxf86dga+=	libXxf86dga>=1.0.1
BUILDLINK_PKGSRCDIR.libXxf86dga?=	../../x11/libXxf86dga
.endif	# LIBXXF86DGA_BUILDLINK3_MK

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xf86dgaproto/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}

.endif
