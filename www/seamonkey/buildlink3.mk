# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/03/30 19:15:47 ghen Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
SEAMONKEY_BUILDLINK3_MK:=		${SEAMONKEY_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=			seamonkey
.endif

BUILDLINK_PACKAGES:=			${BUILDLINK_PACKAGES:Nseamonkey}
BUILDLINK_PACKAGES+=			seamonkey

.if !empty(SEAMONKEY_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.seamonkey+=		seamonkey>=1.0
BUILDLINK_RECOMMENDED.seamonkey+=	seamonkey>=1.0
BUILDLINK_PKGSRCDIR.seamonkey?=		../../wip/seamonkey
.endif	# SEAMONKEY_BUILDLINK3_MK

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../net/libIDL/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=     			${BUILDLINK_DEPTH:S/+$//}
