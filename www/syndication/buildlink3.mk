# $NetBSD: buildlink3.mk,v 1.2 2021/04/21 11:40:44 adam Exp $

BUILDLINK_TREE+=	syndication

.if !defined(SYNDICATION_BUILDLINK3_MK)
SYNDICATION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.syndication+=	syndication>=5.70.0
BUILDLINK_ABI_DEPENDS.syndication?=	syndication>=5.80.0nb1
BUILDLINK_PKGSRCDIR.syndication?=	../../www/syndication

.include "../../textproc/kcodecs/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# SYNDICATION_BUILDLINK3_MK

BUILDLINK_TREE+=	-syndication
