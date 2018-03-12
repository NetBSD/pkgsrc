# $NetBSD: buildlink3.mk,v 1.8 2018/03/12 11:15:46 wiz Exp $

BUILDLINK_TREE+=	sonnet

.if !defined(SONNET_BUILDLINK3_MK)
SONNET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sonnet+=	sonnet>=5.19.0
BUILDLINK_ABI_DEPENDS.sonnet?=	sonnet>=5.41.0nb4
BUILDLINK_PKGSRCDIR.sonnet?=	../../textproc/sonnet

#.include "../../textproc/aspell/buildlink3.mk"
#.include "../../textproc/hunspell/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# SONNET_BUILDLINK3_MK

BUILDLINK_TREE+=	-sonnet
