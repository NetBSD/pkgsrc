# $NetBSD: buildlink3.mk,v 1.3 2007/11/23 14:34:34 bjs Exp $

.include "../../mk/bsd.fast.prefs.mk"

.if ${X11_TYPE} != "modular"
.include "../../mk/x11.buildlink3.mk"
.else

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBXKBUI_BUILDLINK3_MK:=	${LIBXKBUI_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libxkbui
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibxkbui}
BUILDLINK_PACKAGES+=	libxkbui
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libxkbui

.if ${LIBXKBUI_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libxkbui+=	libxkbui>=1.0.2
BUILDLINK_PKGSRCDIR.libxkbui?=	../../x11/libxkbui
.endif	# LIBXKBUI_BUILDLINK3_MK

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}

.endif
