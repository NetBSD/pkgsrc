# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:25:33 joerg Exp $

BUILDLINK_TREE+=	sary

.if !defined(SARY_BUILDLINK3_MK)
SARY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sary+=	sary>=1.2.0
BUILDLINK_PKGSRCDIR.sary?=	../../textproc/sary

.include "../../devel/glib2/buildlink3.mk"
.endif # SARY_BUILDLINK3_MK

BUILDLINK_TREE+=	-sary
