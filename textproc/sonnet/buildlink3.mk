# $NetBSD: buildlink3.mk,v 1.20 2020/11/05 09:07:11 ryoon Exp $

BUILDLINK_TREE+=	sonnet

.if !defined(SONNET_BUILDLINK3_MK)
SONNET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sonnet+=	sonnet>=5.19.0
BUILDLINK_ABI_DEPENDS.sonnet?=	sonnet>=5.70.0nb3
BUILDLINK_PKGSRCDIR.sonnet?=	../../textproc/sonnet

#.include "../../textproc/aspell/buildlink3.mk"
#.include "../../textproc/hunspell/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# SONNET_BUILDLINK3_MK

BUILDLINK_TREE+=	-sonnet
