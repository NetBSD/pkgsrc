# $NetBSD: buildlink3.mk,v 1.2 2007/01/10 17:09:32 joerg Exp $

.include "../../mk/bsd.fast.prefs.mk"

.if ${X11_TYPE} != "modular"
.include "../../mk/x11.buildlink3.mk"
.else

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBXXF86MISC_BUILDLINK3_MK:=	${LIBXXF86MISC_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libXxf86misc
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NlibXxf86misc}
BUILDLINK_PACKAGES+=	libXxf86misc
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libXxf86misc

.if ${LIBXXF86MISC_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libXxf86misc+=	libXxf86misc>=1.0.0
BUILDLINK_PKGSRCDIR.libXxf86misc?=	../../x11/libXxf86misc
.endif	# LIBXXF86MISC_BUILDLINK3_MK

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xf86miscproto/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}

.endif
