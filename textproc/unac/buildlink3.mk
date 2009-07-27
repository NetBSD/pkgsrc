# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/07/27 13:46:57 drochner Exp $

BUILDLINK_TREE+=	unac

.if !defined(UNAC_BUILDLINK3_MK)
UNAC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.unac+=	unac>=1.7.0
BUILDLINK_PKGSRCDIR.unac?=	../../textproc/unac
.endif	# UNAC_BUILDLINK3_MK

BUILDLINK_TREE+=	-unac
