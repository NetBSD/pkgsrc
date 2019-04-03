# $NetBSD: buildlink3.mk,v 1.7 2019/04/03 00:33:09 ryoon Exp $

BUILDLINK_TREE+=	syntax-highlighting

.if !defined(SYNTAX_HIGHLIGHTING_BUILDLINK3_MK)
SYNTAX_HIGHLIGHTING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.syntax-highlighting+=	syntax-highlighting>=5.41.0
BUILDLINK_ABI_DEPENDS.syntax-highlighting?=	syntax-highlighting>=5.47.0nb6
BUILDLINK_PKGSRCDIR.syntax-highlighting?=	../../textproc/syntax-highlighting

.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# SYNTAX_HIGHLIGHTING_BUILDLINK3_MK

BUILDLINK_TREE+=	-syntax-highlighting
