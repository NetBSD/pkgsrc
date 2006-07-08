# $NetBSD: buildlink3.mk,v 1.7 2006/07/08 23:11:13 jlam Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
SEAMONKEY_BUILDLINK3_MK:=		${SEAMONKEY_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=			seamonkey
.endif

BUILDLINK_PACKAGES:=			${BUILDLINK_PACKAGES:Nseamonkey}
BUILDLINK_PACKAGES+=			seamonkey
BUILDLINK_ORDER:=			${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}seamonkey

.if !empty(SEAMONKEY_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.seamonkey+=	seamonkey>=1.0
BUILDLINK_ABI_DEPENDS.seamonkey?=		seamonkey>=1.0.1nb1
BUILDLINK_PKGSRCDIR.seamonkey?=		../../www/seamonkey
.endif	# SEAMONKEY_BUILDLINK3_MK

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../net/libIDL/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
