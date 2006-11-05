# $NetBSD: buildlink3.mk,v 1.2 2006/11/05 16:55:28 joerg Exp $

.include "../../mk/bsd.fast.prefs.mk"

.if ${X11_TYPE} != "modular"
.include "../../mk/x11.buildlink3.mk"
.else

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBXI_BUILDLINK3_MK:=	${LIBXI_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libXi
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NlibXi}
BUILDLINK_PACKAGES+=	libXi
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libXi

.if ${LIBXI_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libXi+=	libXi>=1.0.0
BUILDLINK_PKGSRCDIR.libXi?=	../../x11/libXi
.endif	# LIBXI_BUILDLINK3_MK

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}

.endif
