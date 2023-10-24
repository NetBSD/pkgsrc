# $NetBSD: buildlink3.mk,v 1.9 2023/10/24 22:11:35 wiz Exp $

BUILDLINK_TREE+=	syndication

.if !defined(SYNDICATION_BUILDLINK3_MK)
SYNDICATION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.syndication+=	syndication>=5.70.0
BUILDLINK_ABI_DEPENDS.syndication?=	syndication>=5.108.0nb1
BUILDLINK_PKGSRCDIR.syndication?=	../../www/syndication

.include "../../textproc/kcodecs/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# SYNDICATION_BUILDLINK3_MK

BUILDLINK_TREE+=	-syndication
