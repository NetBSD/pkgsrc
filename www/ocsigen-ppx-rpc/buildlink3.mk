# $NetBSD: buildlink3.mk,v 1.1 2022/06/04 10:01:02 jaapb Exp $

BUILDLINK_TREE+=	ocsigen-ppx-rpc

.if !defined(OCSIGEN_PPX_RPC_BUILDLINK3_MK)
OCSIGEN_PPX_RPC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocsigen-ppx-rpc+=	ocsigen-ppx-rpc>=1.0
BUILDLINK_PKGSRCDIR.ocsigen-ppx-rpc?=	../../www/ocsigen-ppx-rpc

.endif	# OCSIGEN_PPX_RPC_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocsigen-ppx-rpc
