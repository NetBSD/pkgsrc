# $NetBSD: buildlink3.mk,v 1.2 2006/11/06 10:29:33 joerg Exp $

.include "../../mk/bsd.fast.prefs.mk"

.if ${X11_TYPE} != "modular"
.include "../../mk/x11.buildlink3.mk"
.else

BUILDLINK_DEPMETHOD.xbitmaps?=	build

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
XBITMAPS_BUILDLINK3_MK:=	${XBITMAPS_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	xbitmaps
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxbitmaps}
BUILDLINK_PACKAGES+=	xbitmaps
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}xbitmaps

.if ${XBITMAPS_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.xbitmaps+=	xbitmaps>=1.0
BUILDLINK_PKGSRCDIR.xbitmaps?=	../../x11/xbitmaps
.endif	# XBITMAPS_BUILDLINK3_MK

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}

.endif
