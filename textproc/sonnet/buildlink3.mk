# $NetBSD: buildlink3.mk,v 1.3 2017/02/06 13:54:51 wiz Exp $

BUILDLINK_TREE+=	sonnet

.if !defined(SONNET_BUILDLINK3_MK)
SONNET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sonnet+=	sonnet>=5.19.0
BUILDLINK_ABI_DEPENDS.sonnet?=	sonnet>=5.25.0nb3
BUILDLINK_PKGSRCDIR.sonnet?=	../../textproc/sonnet

#.include "../../textproc/aspell/buildlink3.mk"
#.include "../../textproc/hunspell/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# SONNET_BUILDLINK3_MK

BUILDLINK_TREE+=	-sonnet
