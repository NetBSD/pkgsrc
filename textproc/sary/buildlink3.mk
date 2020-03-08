# $NetBSD: buildlink3.mk,v 1.8 2020/03/08 16:48:16 wiz Exp $

BUILDLINK_TREE+=	sary

.if !defined(SARY_BUILDLINK3_MK)
SARY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sary+=	sary>=1.2.0
BUILDLINK_ABI_DEPENDS.sary+=	sary>=1.2.0nb5
BUILDLINK_PKGSRCDIR.sary?=	../../textproc/sary

.include "../../devel/glib2/buildlink3.mk"
.endif # SARY_BUILDLINK3_MK

BUILDLINK_TREE+=	-sary
