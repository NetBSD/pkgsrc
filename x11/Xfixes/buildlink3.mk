# $NetBSD: buildlink3.mk,v 1.12 2006/07/11 14:42:03 joerg Exp $

.include "../../mk/bsd.prefs.mk"

.if ${X11_TYPE} == "xorg"
.include "../../mk/x11.buildlink3.mk"
.else

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
XFIXES_BUILDLINK3_MK:=	${XFIXES_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	Xfixes
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NXfixes}
BUILDLINK_PACKAGES+=	Xfixes
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}Xfixes

.if !empty(XFIXES_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.Xfixes+=	Xfixes>=2.0.0
BUILDLINK_ABI_DEPENDS.Xfixes+=	Xfixes>=2.0.1nb2
BUILDLINK_PKGSRCDIR.Xfixes?=	../../x11/Xfixes
.endif	# XFIXES_BUILDLINK3_MK

.include "../../mk/x11.buildlink3.mk"
.include "../../x11/fixesproto/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}

.endif
