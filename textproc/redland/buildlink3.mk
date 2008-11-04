# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/11/04 10:39:40 markd Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
REDLAND_BUILDLINK3_MK:=	${REDLAND_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	redland
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nredland}
BUILDLINK_PACKAGES+=	redland
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}redland

.if ${REDLAND_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.redland+=	redland>=1.0.7
BUILDLINK_PKGSRCDIR.redland?=	../../textproc/redland
.endif	# REDLAND_BUILDLINK3_MK

.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/raptor/buildlink3.mk"
.include "../../textproc/rasqal/buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
