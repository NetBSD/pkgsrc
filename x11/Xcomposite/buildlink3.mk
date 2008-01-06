# $NetBSD: buildlink3.mk,v 1.11 2008/01/06 16:57:41 rillig Exp $

.include "../../mk/bsd.fast.prefs.mk"

.if ${X11_TYPE} != "modular"
.include "../../mk/x11.buildlink3.mk"
.else

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
XCOMPOSITE_BUILDLINK3_MK:=	${XCOMPOSITE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	Xcomposite
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NXcomposite}
BUILDLINK_PACKAGES+=	Xcomposite
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}Xcomposite

.if !empty(XCOMPOSITE_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.Xcomposite+=		Xcomposite>=1.0.1
BUILDLINK_ABI_DEPENDS.Xcomposite?=	Xcomposite>=1.0.1nb2
BUILDLINK_PKGSRCDIR.Xcomposite?=	../../x11/Xcomposite
.endif	# XCOMPOSITE_BUILDLINK3_MK

.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/compositeproto/buildlink3.mk"
.include "../../x11/fixesproto/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}

.endif
