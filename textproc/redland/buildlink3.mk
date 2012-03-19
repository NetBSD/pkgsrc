# $NetBSD: buildlink3.mk,v 1.8 2012/03/19 09:40:08 markd Exp $

BUILDLINK_TREE+=	redland

.if !defined(REDLAND_BUILDLINK3_MK)
REDLAND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.redland+=	redland>=1.0.7
BUILDLINK_ABI_DEPENDS.redland?=	redland>=1.0.12nb3
BUILDLINK_PKGSRCDIR.redland?=	../../textproc/redland

.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/raptor2/buildlink3.mk"
.include "../../textproc/rasqal/buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"
.endif # REDLAND_BUILDLINK3_MK

BUILDLINK_TREE+=	-redland
