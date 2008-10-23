# $NetBSD: buildlink3.mk,v 1.2 2008/10/23 05:10:53 obache Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
TOKYODYSTOPIA_BUILDLINK3_MK:=	${TOKYODYSTOPIA_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	tokyodystopia
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ntokyodystopia}
BUILDLINK_PACKAGES+=	tokyodystopia
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}tokyodystopia

.if ${TOKYODYSTOPIA_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.tokyodystopia+=	tokyodystopia>=0.9.5
BUILDLINK_PKGSRCDIR.tokyodystopia?=	../../textproc/tokyodystopia
.endif	# TOKYODYSTOPIA_BUILDLINK3_MK

.include "../../databases/tokyocabinet/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
