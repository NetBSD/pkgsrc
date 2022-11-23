# $NetBSD: buildlink3.mk,v 1.19 2022/11/23 16:19:04 adam Exp $

BUILDLINK_TREE+=	syntax-highlighting

.if !defined(SYNTAX_HIGHLIGHTING_BUILDLINK3_MK)
SYNTAX_HIGHLIGHTING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.syntax-highlighting+=	syntax-highlighting>=5.41.0
BUILDLINK_ABI_DEPENDS.syntax-highlighting?=	syntax-highlighting>=5.98.0nb1
BUILDLINK_PKGSRCDIR.syntax-highlighting?=	../../textproc/syntax-highlighting

.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# SYNTAX_HIGHLIGHTING_BUILDLINK3_MK

BUILDLINK_TREE+=	-syntax-highlighting
