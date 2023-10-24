# $NetBSD: buildlink3.mk,v 1.28 2023/10/24 22:11:20 wiz Exp $

BUILDLINK_TREE+=	sonnet

.if !defined(SONNET_BUILDLINK3_MK)
SONNET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sonnet+=	sonnet>=5.19.0
BUILDLINK_ABI_DEPENDS.sonnet?=	sonnet>=5.108.0nb1
BUILDLINK_PKGSRCDIR.sonnet?=	../../textproc/sonnet

#.include "../../textproc/aspell/buildlink3.mk"
#.include "../../textproc/hunspell/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# SONNET_BUILDLINK3_MK

BUILDLINK_TREE+=	-sonnet
